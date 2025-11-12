#include "Microsoft.Xbox.Services.Tournaments.CurrentMatchMetadata.h"
#include "Microsoft.Xbox.Services.Tournaments.CurrentMatchMetadata.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Tournaments::implementation
{
winrt::Microsoft::Xbox::Services::Multiplayer::MultiplayerSessionReference CurrentMatchMetadata::GameSessionReference()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Microsoft::Xbox::Services::Tournaments::MatchMetadata CurrentMatchMetadata::MatchDetails()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Tournaments::implementation
