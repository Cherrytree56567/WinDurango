#include "Microsoft.Xbox.Services.XboxLiveWnsEventArgs.h"
#include "Microsoft.Xbox.Services.XboxLiveWnsEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::implementation
{
hstring XboxLiveWnsEventArgs::XboxUserId()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
hstring XboxLiveWnsEventArgs::NotificationType()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::implementation
