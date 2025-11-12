#include "Windows.Xbox.Speech.Recognition.InstalledSpeechRecognizers.h"
#include "Windows.Xbox.Speech.Recognition.InstalledSpeechRecognizers.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Speech::Recognition::implementation
{
winrt::Windows::Foundation::Collections::IVectorView<
    winrt::Windows::Xbox::Speech::Recognition::SpeechRecognizerInformation>
InstalledSpeechRecognizers::All()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Windows::Xbox::Speech::Recognition::SpeechRecognizerInformation InstalledSpeechRecognizers::Default()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Speech::Recognition::implementation
