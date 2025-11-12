#include "Windows.Xbox.Chat.ChatChannel.h"
#include "Windows.Xbox.Chat.ChatChannel.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Xbox::Chat::IChatParticipant> ChatChannel::
    Participants()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Chat::implementation
