#include "Microsoft.Xbox.Services.Statistics.Manager.LeaderboardResultEventArgs.h"
#include "Microsoft.Xbox.Services.Statistics.Manager.LeaderboardResultEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Statistics::Manager::implementation
{
winrt::Microsoft::Xbox::Services::Leaderboard::LeaderboardResult LeaderboardResultEventArgs::Result()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Statistics::Manager::implementation
