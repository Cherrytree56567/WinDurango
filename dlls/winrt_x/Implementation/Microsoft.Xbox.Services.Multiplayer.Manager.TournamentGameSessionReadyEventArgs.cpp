#include "Microsoft.Xbox.Services.Multiplayer.Manager.TournamentGameSessionReadyEventArgs.h"
#include "Microsoft.Xbox.Services.Multiplayer.Manager.TournamentGameSessionReadyEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
{
winrt::Windows::Foundation::DateTime TournamentGameSessionReadyEventArgs::StartTime()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
