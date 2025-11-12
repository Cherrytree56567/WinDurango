#include "Windows.Xbox.Speech.Recognition.SpeechRecognizerPhraseStartedEventArgs.h"
#include "Windows.Xbox.Speech.Recognition.SpeechRecognizerPhraseStartedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Speech::Recognition::implementation
{
winrt::Windows::Xbox::Speech::Recognition::SpeechRecognizerAudioContext SpeechRecognizerPhraseStartedEventArgs::
    AudioContext()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Speech::Recognition::implementation
