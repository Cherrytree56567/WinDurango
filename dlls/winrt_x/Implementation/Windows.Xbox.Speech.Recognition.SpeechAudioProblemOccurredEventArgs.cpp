#include "Windows.Xbox.Speech.Recognition.SpeechAudioProblemOccurredEventArgs.h"
#include "Windows.Xbox.Speech.Recognition.SpeechAudioProblemOccurredEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Speech::Recognition::implementation
{
winrt::Windows::Xbox::Speech::Recognition::SpeechRecognitionAudioProblem SpeechAudioProblemOccurredEventArgs::Problem()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Speech::Recognition::implementation
