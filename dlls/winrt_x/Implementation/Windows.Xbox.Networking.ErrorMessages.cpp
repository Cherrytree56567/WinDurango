#include "Windows.Xbox.Networking.ErrorMessages.h"
#include "Windows.Xbox.Networking.ErrorMessages.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
hstring ErrorMessages::GetMessageForError(uint32_t errorCode)
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Networking::implementation
