#include "Windows.Xbox.Media.GameTransportControlsPropertyChangedEventArgs.h"
#include "Windows.Xbox.Media.GameTransportControlsPropertyChangedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Media::implementation
{
winrt::Windows::Xbox::Media::GameTransportControlsProperty GameTransportControlsPropertyChangedEventArgs::Property()
{
    return m_property;
}
} // namespace winrt::Windows::Xbox::Media::implementation
