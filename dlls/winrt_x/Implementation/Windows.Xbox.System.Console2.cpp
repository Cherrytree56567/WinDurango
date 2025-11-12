#include "Windows.Xbox.System.Console2.h"
#include "Windows.Xbox.System.Console2.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::System::implementation
{
hstring Console2::ApplicationSpecificDeviceId()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::System::implementation
