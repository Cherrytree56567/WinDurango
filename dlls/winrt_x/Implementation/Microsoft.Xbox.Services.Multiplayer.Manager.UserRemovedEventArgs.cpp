#include "Microsoft.Xbox.Services.Multiplayer.Manager.UserRemovedEventArgs.h"
#include "Microsoft.Xbox.Services.Multiplayer.Manager.UserRemovedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
{
hstring UserRemovedEventArgs::XboxUserId()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
