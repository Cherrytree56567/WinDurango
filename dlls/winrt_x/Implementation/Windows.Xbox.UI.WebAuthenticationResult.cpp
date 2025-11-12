#include "Windows.Xbox.UI.WebAuthenticationResult.h"
#include "Windows.Xbox.UI.WebAuthenticationResult.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::UI::implementation
{
hstring WebAuthenticationResult::ResponseData()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Windows::Xbox::UI::WebAuthenticationStatus WebAuthenticationResult::ResponseStatus()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
uint32_t WebAuthenticationResult::ResponseErrorDetail()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::UI::implementation
