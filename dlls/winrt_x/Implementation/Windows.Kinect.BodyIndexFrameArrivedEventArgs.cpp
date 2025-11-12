#include "Windows.Kinect.BodyIndexFrameArrivedEventArgs.h"
#include "Windows.Kinect.BodyIndexFrameArrivedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
winrt::Windows::Kinect::BodyIndexFrameReference BodyIndexFrameArrivedEventArgs::FrameReference()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
