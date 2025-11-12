#include "Windows.Xbox.Multiplayer.GameSessionReadyEventArgs.h"
#include "Windows.Xbox.Multiplayer.GameSessionReadyEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Multiplayer::implementation
{
winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference GameSessionReadyEventArgs::GameSession()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Multiplayer::implementation
