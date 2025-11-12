#include "Windows.Xbox.UI.Accessibility.h"
#include "Windows.Xbox.UI.Accessibility.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::UI::implementation
{
void Accessibility::SetSpeechToTextPositionHint(winrt::Windows::Xbox::UI::SpeechToTextPositionHint const &position)
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
void Accessibility::SendSpeechToTextString(hstring const &speakerName, hstring const &content,
                                           winrt::Windows::Xbox::UI::SpeechToTextType const &type)
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::UI::implementation
