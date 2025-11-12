#include "Windows.Xbox.ApplicationModel.Store.Configuration.h"
#include "Windows.Xbox.ApplicationModel.Store.Configuration.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::ApplicationModel::Store::implementation
{
hstring Configuration::MarketplaceId()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::ApplicationModel::Store::implementation
