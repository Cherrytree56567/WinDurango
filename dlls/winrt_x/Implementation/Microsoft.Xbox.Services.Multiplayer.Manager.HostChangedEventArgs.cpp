#include "Microsoft.Xbox.Services.Multiplayer.Manager.HostChangedEventArgs.h"
#include "Microsoft.Xbox.Services.Multiplayer.Manager.HostChangedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
{
winrt::Microsoft::Xbox::Services::Multiplayer::Manager::MultiplayerMember HostChangedEventArgs::HostMember()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
