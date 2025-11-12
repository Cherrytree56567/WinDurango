#include "Windows.Kinect.DepthFrameReference.h"
#include "Windows.Kinect.DepthFrameReference.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
winrt::Windows::Kinect::DepthFrame DepthFrameReference::AcquireFrame()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Windows::Foundation::TimeSpan DepthFrameReference::RelativeTime()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
