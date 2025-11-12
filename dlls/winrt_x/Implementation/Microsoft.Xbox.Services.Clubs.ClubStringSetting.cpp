#include "Microsoft.Xbox.Services.Clubs.ClubStringSetting.h"
#include "Microsoft.Xbox.Services.Clubs.ClubStringSetting.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Clubs::implementation
{
hstring ClubStringSetting::Value()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Windows::Foundation::Collections::IVectorView<hstring> ClubStringSetting::AllowedValues()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
bool ClubStringSetting::CanViewerChangeSetting()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Clubs::implementation
