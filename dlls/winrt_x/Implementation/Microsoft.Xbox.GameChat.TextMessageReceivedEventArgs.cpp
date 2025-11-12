#include "Microsoft.Xbox.GameChat.TextMessageReceivedEventArgs.h"
#include "Microsoft.Xbox.GameChat.TextMessageReceivedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::GameChat::implementation
{
hstring TextMessageReceivedEventArgs::Message()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Microsoft::Xbox::GameChat::ChatTextMessageType TextMessageReceivedEventArgs::ChatTextMessageType()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Microsoft::Xbox::GameChat::ChatUser TextMessageReceivedEventArgs::ChatUser()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::GameChat::implementation
