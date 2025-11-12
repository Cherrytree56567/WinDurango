#include "Windows.Kinect.BodyFrameArrivedEventArgs.h"
#include "Windows.Kinect.BodyFrameArrivedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
winrt::Windows::Kinect::BodyFrameReference BodyFrameArrivedEventArgs::FrameReference()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
