#include "Windows.Kinect.IsPausedChangedEventArgs.h"
#include "Windows.Kinect.IsPausedChangedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
bool IsPausedChangedEventArgs::IsPaused()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
