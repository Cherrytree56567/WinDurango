// ReSharper disable CppFunctionResultShouldBeUsed
#include "pch.h"
#include "Windows.Xbox.Storage.ConnectedStorage.h"
#include "Windows.Xbox.Storage.BlobInfoQueryResult.h"

#include <winrt/Windows.Storage.FileProperties.h>
#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Storage.h>

#include <robuffer.h>
#include <shlobj.h>
#include <strsafe.h>

using namespace WinDurango::impl;

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::Storage;
using namespace winrt::Windows::Storage::Streams;
using namespace winrt::Windows::Xbox::Storage;

IAsyncAction ConnectedStorage::CreateContainer(hstring name) const
{
    if (m_storagePath.empty()) 
    {
        LOG_ERROR("[ConnectedStorage] Storage path not initialized\n");
        
    	co_return;
    }

    if (const hstring containerPath = m_storagePath + L"\\" + name; !co_await DoesFolderExist(containerPath))
    {
        try
        {
            const auto folder = co_await StorageFolder::GetFolderFromPathAsync(m_storagePath);

            co_await folder.CreateFolderAsync(name, CreationCollisionOption::OpenIfExists);

            LOG_INFO("[ConnectedStorage] Container %S created\n", name.c_str());
        }
        catch (hresult_error const& ex)
        {
            LOG_ERROR("[ConnectedStorage] Failed to create container %S: %S\n", name.c_str(), ex.message().c_str());

            throw;
        }
    }
}

IAsyncAction ConnectedStorage::Read(hstring containerName, IMapView<hstring, IBuffer> data) const
{
    if (data == nullptr) {
        LOG_WARNING("[ConnectedStorage] Read called with null data map\n");
        co_return;
    }

    if (m_storagePath.empty()) {
        LOG_ERROR("[ConnectedStorage] Storage path not initialized\n");
        co_return;
    }

    const hstring containerPath = m_storagePath + L"\\" + containerName;

    if (!co_await DoesFolderExist(containerPath)) {
        co_await CreateContainer(containerName);
        LOG_INFO("[ConnectedStorage] Container %S created during read\n", containerName.c_str());
    }

    try
    {
        const auto folder = co_await StorageFolder::GetFolderFromPathAsync(containerPath);

        for (auto const& pair : data)
        {
            try
            {
                auto fileName = pair.Key();
                auto dataBuffer = pair.Value();

                if (dataBuffer == nullptr) {
                    LOG_WARNING("[ConnectedStorage] Null buffer for file %S\n", fileName.c_str());

                    continue;
                }

                auto file = co_await folder.GetFileAsync(fileName);
                auto fileBuffer = co_await FileIO::ReadBufferAsync(file);

                // Validate buffer capacity
                if (dataBuffer.Capacity() < fileBuffer.Length()) 
                {
                    LOG_ERROR("[ConnectedStorage] Buffer too small for file %S (need %u, have %u)\n",
                        fileName.c_str(), fileBuffer.Length(), dataBuffer.Capacity());

                    continue;
                }

                // Get raw buffer pointers
                const auto bufferByteAccess = fileBuffer.as<Windows::Storage::Streams::IBufferByteAccess>();
                uint8_t* fileData = nullptr;
                bufferByteAccess->Buffer(&fileData);

                const auto dataBufferByteAccess = dataBuffer.as<Windows::Storage::Streams::IBufferByteAccess>();
                uint8_t* dataBufferData = nullptr;
                dataBufferByteAccess->Buffer(&dataBufferData);

                if (fileData != nullptr && dataBufferData != nullptr) 
                {
                    memcpy(dataBufferData, fileData, fileBuffer.Length());

                    dataBuffer.Length(fileBuffer.Length()); // Set the actual data length

                    LOG_INFO("[ConnectedStorage] Successfully read file %S (%u bytes)\n", fileName.c_str(), fileBuffer.Length());
                }
                else 
                {
                    LOG_ERROR("[ConnectedStorage] Failed to get buffer pointers for file %S\n", fileName.c_str());
                }
            }
            catch (hresult_error const& ex)
            {
                LOG_ERROR("[ConnectedStorage] Failed to read file %S: %S (0x%08X)\n", pair.Key().c_str(), ex.message().c_str(), ex.code());
            }
        }
    }
    catch (hresult_error const& ex)
    {
        LOG_ERROR("[ConnectedStorage] Failed to access container %S: %S\n", containerName.c_str(), ex.message().c_str());

        throw;
    }
}

IAsyncAction ConnectedStorage::Upload(hstring containerName, IMapView<hstring, IBuffer> blobsToWrite, IIterable<hstring> blobsToDelete, hstring displayName) const
{
    if (m_storagePath.empty()) 
    {
        LOG_ERROR("[ConnectedStorage] Storage path not initialized\n");

        co_return;
    }

    const hstring containerPath = m_storagePath + L"\\" + containerName;

    if (!co_await DoesFolderExist(containerPath)) 
    {
        co_await CreateContainer(containerName);

        LOG_INFO("[ConnectedStorage] Container %S created during upload\n", containerName.c_str());
    }

    try
    {
        const auto folder = co_await StorageFolder::GetFolderFromPathAsync(containerPath);

        // Write display name if provided
        if (!displayName.empty())
        {
            try
            {
                const auto file = co_await folder.CreateFileAsync(L"wd_displayname.txt", CreationCollisionOption::ReplaceExisting);

                co_await FileIO::WriteTextAsync(file, displayName);

                LOG_INFO("[ConnectedStorage] Display name written: %S\n", displayName.c_str());
            }
            catch (hresult_error const& ex)
            {
                LOG_ERROR("[ConnectedStorage] Failed to write display name: %S\n", ex.message().c_str());
            }
        }

        // Write blobs
        if (blobsToWrite != nullptr)
        {
            for (auto const& pair : blobsToWrite)
            {
                try
                {
                    auto fileName = pair.Key();
                    auto dataBuffer = pair.Value();

                    if (dataBuffer == nullptr) 
                    {
                        LOG_WARNING("[ConnectedStorage] Null buffer for file %S, skipping\n", fileName.c_str());
                        continue;
                    }

                    auto file = co_await folder.CreateFileAsync(fileName, CreationCollisionOption::ReplaceExisting);

                    co_await FileIO::WriteBufferAsync(file, dataBuffer);

                    LOG_INFO("[ConnectedStorage] Written file %S (%u bytes)\n", fileName.c_str(), dataBuffer.Length());
                }
                catch (hresult_error const& ex)
                {
                    LOG_ERROR("[ConnectedStorage] Failed to write file %S: %S\n", pair.Key().c_str(), ex.message().c_str());
                }
            }
        }

        // Delete blobs
        if (blobsToDelete != nullptr)
        {
            for (auto const& blobName : blobsToDelete)
            {
                try
                {
                    auto file = co_await folder.GetFileAsync(blobName);

                    co_await file.DeleteAsync();

                    LOG_INFO("[ConnectedStorage] Deleted file %S\n", blobName.c_str());
                }
                catch (hresult_error const& ex)
                {
                    // File might not exist, which is acceptable
                    if (ex.code() != HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)) {
                        LOG_ERROR("[ConnectedStorage] Failed to delete file %S: %S\n", blobName.c_str(), ex.message().c_str());
                    }
                }
            }
        }
    }
    catch (hresult_error const& ex)
    {
        LOG_ERROR("[ConnectedStorage] Failed to access container %S: %S\n", containerName.c_str(), ex.message().c_str());
        throw;
    }
}

IAsyncOperation<IVectorView<BlobInfo>> ConnectedStorage::GetBlobInfoAsync(hstring parentContainerName, hstring blobNamePrefix)
{
    const IVector<BlobInfo> blobInfoVector = winrt::single_threaded_vector<BlobInfo>();

    if (m_storagePath.empty()) 
    {
        LOG_ERROR("[ConnectedStorage] Storage path not initialized\n");

        co_return blobInfoVector.GetView();
    }

    hstring storagePath = m_storagePath + L"\\" + parentContainerName;

    if (!co_await DoesFolderExist(storagePath)) {
        LOG_INFO("[ConnectedStorage] Container %S does not exist for blob query\n", parentContainerName.c_str());
        co_return blobInfoVector.GetView();
    }

    try
    {
        auto storageFolder = co_await StorageFolder::GetFolderFromPathAsync(storagePath);
        auto files = co_await storageFolder.GetFilesAsync();

        for (auto file : files)
        {
            std::wstring_view fileName{ file.Name() };

            // Skip display name metadata file
            if (fileName == L"wd_displayname.txt") {
                continue;
            }

            // Check prefix match
            if (!blobNamePrefix.empty() && !fileName.starts_with(blobNamePrefix)) {
                continue;
            }

            try
            {
                auto fileProperties = co_await file.GetBasicPropertiesAsync();
                uint32_t size = static_cast<uint32_t>(fileProperties.Size());
                blobInfoVector.Append({ file.Name(), size });
            }
            catch (hresult_error const& ex)
            {
                LOG_ERROR("[ConnectedStorage] Failed to get properties for %S: %S\n",
                    file.Name().c_str(), ex.message().c_str());
            }
        }
    }
    catch (hresult_error const& ex)
    {
        LOG_ERROR("[ConnectedStorage] Failed to query blobs in container %S: %S\n",
            parentContainerName.c_str(), ex.message().c_str());
    }

    co_return blobInfoVector.GetView();
}

IAsyncOperation<IVectorView<ContainerInfo2>>
ConnectedStorage::GetContainerInfo2Async()
{
    IVector<ContainerInfo2> containerInfoVector =
        winrt::single_threaded_vector<ContainerInfo2>();

    if (m_storagePath.empty()) {
        LOG_ERROR("[ConnectedStorage] Storage path not initialized\n");
        co_return containerInfoVector.GetView();
    }

    try
    {
        auto storageFolder = co_await StorageFolder::GetFolderFromPathAsync(m_storagePath);
        auto folders = co_await storageFolder.GetFoldersAsync();

        for (auto folder : folders)
        {
            try
            {
                auto folderProperties = co_await folder.GetBasicPropertiesAsync();
                uint64_t size = folderProperties.Size();
                DateTime date = folderProperties.DateModified();

                // Check for custom display name
                hstring displayName = {};
                if (co_await DoesFileExist(folder, L"wd_displayname.txt"))
                {
                    try
                    {
                        auto file = co_await folder.GetFileAsync(L"wd_displayname.txt");
                        displayName = co_await FileIO::ReadTextAsync(file);
                    }
                    catch (hresult_error const& ex)
                    {
                        LOG_WARNING("[ConnectedStorage] Failed to read display name for %S: %S\n",
                            folder.Name().c_str(), ex.message().c_str());
                    }
                }

                if (displayName.empty()) {
                    displayName = folder.DisplayName();
                }

                containerInfoVector.Append({ folder.Name(), size, displayName, date, false });
            }
            catch (hresult_error const& ex)
            {
                LOG_ERROR("[ConnectedStorage] Failed to get info for container %S: %S\n",
                    folder.Name().c_str(), ex.message().c_str());
            }
        }
    }
    catch (hresult_error const& ex)
    {
        LOG_ERROR("[ConnectedStorage] Failed to query containers: %S\n", ex.message().c_str());
    }

    co_return containerInfoVector.GetView();
}

IAsyncAction ConnectedStorage::DeleteContainer(hstring containerName)
{
    if (m_storagePath.empty()) {
        LOG_ERROR("[ConnectedStorage] Storage path not initialized\n");
        co_return;
    }

    hstring containerPath = m_storagePath + L"\\" + containerName;

    if (co_await DoesFolderExist(containerPath))
    {
        try
        {
            auto folder = co_await StorageFolder::GetFolderFromPathAsync(containerPath);
            co_await folder.DeleteAsync();
            LOG_INFO("[ConnectedStorage] Container %S deleted\n", containerName.c_str());
        }
        catch (hresult_error const& ex)
        {
            LOG_ERROR("[ConnectedStorage] Failed to delete container %S: %S\n",
                containerName.c_str(), ex.message().c_str());
            throw;
        }
    }
    else
    {
        LOG_WARNING("[ConnectedStorage] Container %S does not exist, cannot delete\n", containerName.c_str());
    }
}

hstring ConnectedStorage::ObtainPackageName()
{
    try
    {
        return Windows::ApplicationModel::Package::Current().Id().FamilyName();
    }
    catch (hresult_error const& ex)
    {
        LOG_ERROR("[ConnectedStorage] Failed to obtain package name: %S\n", ex.message().c_str());
        return {};
    }
}

IAsyncOperation<bool> ConnectedStorage::DoesFolderExist(hstring path)
{
    try
    {
        co_await StorageFolder::GetFolderFromPathAsync(path);
        co_return true;
    }
    catch (hresult_error const& ex)
    {
        if (ex.code() == HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) ||
            ex.code() == HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND))
        {
            co_return false;
        }
        else
        {
            LOG_ERROR("[ConnectedStorage] Unexpected error checking folder existence %S: %S\n",
                path.c_str(), ex.message().c_str());
            throw;
        }
    }
}

IAsyncOperation<bool> ConnectedStorage::DoesFileExist(
    Windows::Storage::StorageFolder folder,
    hstring path)
{
    try
    {
        co_await folder.GetFileAsync(path);
        co_return true;
    }
    catch (hresult_error const& ex)
    {
        if (ex.code() == HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND))
        {
            co_return false;
        }
        else
        {
            LOG_ERROR("[ConnectedStorage] Unexpected error checking file existence %S: %S\n",
                path.c_str(), ex.message().c_str());
            throw;
        }
    }
}

IAsyncAction ConnectedStorage::CreateDirectories(
    const wchar_t* storageType,
    hstring& storagePath)
{
    // CRITICAL FIX: Removed co_await winrt::resume_background() to prevent threading violations
    // WinRT async operations are already non-blocking and must stay on correct apartment thread

    hstring packageName = ObtainPackageName();
    if (packageName.empty()) {
        LOG_ERROR("[ConnectedStorage] Failed to obtain package name\n");
        co_return;
    }

    try
    {
        auto localFolder = ApplicationData::Current().LocalFolder();
        hstring basePath = localFolder.Path();
        hstring winDurangoPath = basePath + L"\\WinDurango";

        // Create WinDurango folder if needed
        if (!co_await DoesFolderExist(winDurangoPath))
        {
            co_await localFolder.CreateFolderAsync(L"WinDurango",
                CreationCollisionOption::OpenIfExists);
            LOG_INFO("[ConnectedStorage] Created WinDurango base folder\n");
        }

        // Create storage type folder
        hstring folderPath = winDurangoPath + L"\\" + storageType;

        if (!co_await DoesFolderExist(folderPath))
        {
            auto winDurangoFolder = co_await StorageFolder::GetFolderFromPathAsync(winDurangoPath);
            co_await winDurangoFolder.CreateFolderAsync(storageType,
                CreationCollisionOption::OpenIfExists);
            LOG_INFO("[ConnectedStorage] Created storage type folder: %S\n", storageType);
        }

        storagePath = folderPath;
    }
    catch (hresult_error const& ex)
    {
        LOG_ERROR("[ConnectedStorage] Failed to create directories for %S: %S\n",
            storageType, ex.message().c_str());
        throw;
    }
}

IAsyncAction ConnectedStorage::InitializeStorage(const wchar_t* name)
{
    try
    {
        co_await CreateDirectories(name, m_storagePath);
        LOG_INFO("[ConnectedStorage] User storage initialized at %S\n", m_storagePath.c_str());
    }
    catch (hresult_error const& ex)
    {
        LOG_ERROR("[ConnectedStorage] Failed to initialize storage: %S\n", ex.message().c_str());
        throw;
    }
}