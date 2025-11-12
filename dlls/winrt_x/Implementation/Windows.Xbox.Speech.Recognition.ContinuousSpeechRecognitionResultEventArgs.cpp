#include "Windows.Xbox.Speech.Recognition.ContinuousSpeechRecognitionResultEventArgs.h"
#include "Windows.Xbox.Speech.Recognition.ContinuousSpeechRecognitionResultEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Speech::Recognition::implementation
{
winrt::Windows::Xbox::Speech::Recognition::SpeechRecognitionResult ContinuousSpeechRecognitionResultEventArgs::Result()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Speech::Recognition::implementation
