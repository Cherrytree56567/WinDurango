#include "Windows.Xbox.Media.GameTransportControlsButtonPressedEventArgs.h"
#include "Windows.Xbox.Media.GameTransportControlsButtonPressedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Media::implementation
{
winrt::Windows::Xbox::Media::GameTransportControlsButton GameTransportControlsButtonPressedEventArgs::Button()
{
    GameTransportControlsButton button{};

    return button;
}
} // namespace winrt::Windows::Xbox::Media::implementation
