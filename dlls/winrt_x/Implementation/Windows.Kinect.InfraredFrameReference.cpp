#include "Windows.Kinect.InfraredFrameReference.h"
#include "Windows.Kinect.InfraredFrameReference.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
winrt::Windows::Kinect::InfraredFrame InfraredFrameReference::AcquireFrame()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Windows::Foundation::TimeSpan InfraredFrameReference::RelativeTime()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
