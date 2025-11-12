#pragma once
#include "Microsoft.Xbox.Services.Multiplayer.Manager.JoinLobbyCompletedEventArgs.g.h"

namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
{
struct JoinLobbyCompletedEventArgs : JoinLobbyCompletedEventArgsT<JoinLobbyCompletedEventArgs>
{
    JoinLobbyCompletedEventArgs() = default;

    hstring InvitedXboxUserId();
};
} // namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
