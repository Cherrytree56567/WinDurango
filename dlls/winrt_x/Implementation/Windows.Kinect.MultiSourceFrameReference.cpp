#include "Windows.Kinect.MultiSourceFrameReference.h"
#include "Windows.Kinect.MultiSourceFrameReference.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
winrt::Windows::Kinect::MultiSourceFrame MultiSourceFrameReference::AcquireFrame()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
