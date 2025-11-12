#include "Windows.Kinect.AudioFrameArrivedEventArgs.h"
#include "Windows.Kinect.AudioFrameArrivedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
winrt::Windows::Kinect::AudioBeamFrameReference AudioFrameArrivedEventArgs::FrameReference()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
