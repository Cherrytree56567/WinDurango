#include "Windows.Kinect.AudioBodyCorrelation.h"
#include "Windows.Kinect.AudioBodyCorrelation.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
uint64_t AudioBodyCorrelation::BodyTrackingId()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
