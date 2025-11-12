#include "Microsoft.Xbox.Services.Multiplayer.Manager.FindMatchCompletedEventArgs.h"
#include "Microsoft.Xbox.Services.Multiplayer.Manager.FindMatchCompletedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
{
winrt::Microsoft::Xbox::Services::Multiplayer::Manager::MatchStatus FindMatchCompletedEventArgs::MatchStatus()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Microsoft::Xbox::Services::Multiplayer::MultiplayerMeasurementFailure FindMatchCompletedEventArgs::
    InitializationFailureCause()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Multiplayer::Manager::implementation
