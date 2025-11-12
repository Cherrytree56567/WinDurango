#include "Microsoft.Xbox.Services.Tournaments.MatchMetadata.h"
#include "Microsoft.Xbox.Services.Tournaments.MatchMetadata.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Tournaments::implementation
{
hstring MatchMetadata::Description()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Windows::Foundation::DateTime MatchMetadata::StartTIme()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
bool MatchMetadata::IsBye()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Windows::Foundation::Collections::IVectorView<hstring> MatchMetadata::OpposingTeamIds()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Tournaments::implementation
