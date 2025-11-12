#include "Windows.Kinect.FrameDescription.h"
#include "Windows.Kinect.FrameDescription.g.cpp"
#include "pch.h"

namespace winrt::Windows::Kinect::implementation
{
int32_t FrameDescription::Width()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
int32_t FrameDescription::Height()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
float FrameDescription::HorizontalFieldOfView()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
float FrameDescription::VerticalFieldOfView()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
float FrameDescription::DiagonalFieldOfView()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
uint32_t FrameDescription::LengthInPixels()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
uint32_t FrameDescription::BytesPerPixel()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Kinect::implementation
