#include "Windows.Xbox.Multiplayer.UserPartyAssociation.h"
#include "Windows.Xbox.Multiplayer.UserPartyAssociation.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Multiplayer::implementation
{
winrt::Windows::Foundation::Collections::IVectorView<hstring> UserPartyAssociation::QueriedXboxUserIds()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
hstring UserPartyAssociation::PartyId()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Multiplayer::implementation
