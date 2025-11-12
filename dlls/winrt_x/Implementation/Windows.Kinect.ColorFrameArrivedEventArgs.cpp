#include "Windows.Kinect.ColorFrameArrivedEventArgs.h"
#include "Windows.Kinect.ColorFrameArrivedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
winrt::Windows::Kinect::ColorFrameReference ColorFrameArrivedEventArgs::FrameReference()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
