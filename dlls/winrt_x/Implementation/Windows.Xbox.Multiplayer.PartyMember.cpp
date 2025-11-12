#include "Windows.Xbox.Multiplayer.PartyMember.h"
#include "Windows.Xbox.Multiplayer.PartyMember.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Multiplayer::implementation
{
hstring PartyMember::XboxUserId()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
bool PartyMember::IsLocal()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
winrt::Windows::Foundation::DateTime PartyMember::JoinTime()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Multiplayer::implementation
