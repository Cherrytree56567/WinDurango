#include "Windows.Xbox.Speech.Recognition.SpeechRecognizerSoundEndedEventArgs.h"
#include "Windows.Xbox.Speech.Recognition.SpeechRecognizerSoundEndedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Speech::Recognition::implementation
{
winrt::Windows::Xbox::Speech::Recognition::SpeechRecognizerAudioContext SpeechRecognizerSoundEndedEventArgs::
    AudioContext()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Speech::Recognition::implementation
