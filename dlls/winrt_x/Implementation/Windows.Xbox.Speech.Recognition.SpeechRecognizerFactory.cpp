#include "Windows.Xbox.Speech.Recognition.SpeechRecognizerFactory.h"
#include "Windows.Xbox.Speech.Recognition.SpeechRecognizerFactory.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Speech::Recognition::implementation
{
winrt::Windows::Xbox::Speech::Recognition::SpeechRecognizer SpeechRecognizerFactory::CreateSpeechRecognizerForLocale(
    uint16_t requestedLanguageId)
{
    LOG_INFO("SpeechRecognizerFactory::CreateSpeechRecognizerForLocale\n");
    return 0;
}
} // namespace winrt::Windows::Xbox::Speech::Recognition::implementation
