#include "Windows.Xbox.Speech.Recognition.SpeechHypothesisResultEventArgs.h"
#include "Windows.Xbox.Speech.Recognition.SpeechHypothesisResultEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Speech::Recognition::implementation
{
winrt::Windows::Xbox::Speech::Recognition::SpeechRecognitionResult SpeechHypothesisResultEventArgs::Hypothesis()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Speech::Recognition::implementation
