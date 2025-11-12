#include "Windows.Xbox.Speech.Recognition.SpeechRecognizerSoundStartedEventArgs.h"
#include "Windows.Xbox.Speech.Recognition.SpeechRecognizerSoundStartedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Speech::Recognition::implementation
{
winrt::Windows::Xbox::Speech::Recognition::SpeechRecognizerAudioContext SpeechRecognizerSoundStartedEventArgs::
    AudioContext()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Speech::Recognition::implementation
