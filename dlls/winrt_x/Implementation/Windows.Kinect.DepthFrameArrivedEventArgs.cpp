#include "Windows.Kinect.DepthFrameArrivedEventArgs.h"
#include "Windows.Kinect.DepthFrameArrivedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
winrt::Windows::Kinect::DepthFrameReference DepthFrameArrivedEventArgs::FrameReference()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
