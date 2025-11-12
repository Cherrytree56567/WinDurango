#pragma once
#include "Windows.Xbox.SmartGlass.SmartGlassMessageReceivedEventArgs.g.h"

namespace winrt::Windows::Xbox::SmartGlass::implementation
{
struct SmartGlassMessageReceivedEventArgs : SmartGlassMessageReceivedEventArgsT<SmartGlassMessageReceivedEventArgs>
{
    SmartGlassMessageReceivedEventArgs() = default;

    hstring Message();
};
} // namespace winrt::Windows::Xbox::SmartGlass::implementation