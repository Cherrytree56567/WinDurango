#include "Windows.Xbox.Chat.ChatUserCorrelation.h"
#include "Windows.Xbox.Chat.ChatUserCorrelation.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
winrt::Windows::Xbox::System::IUser ChatUserCorrelation::User()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Chat::implementation
