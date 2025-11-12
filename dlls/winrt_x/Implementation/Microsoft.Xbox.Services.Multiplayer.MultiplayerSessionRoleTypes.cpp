#include "Microsoft.Xbox.Services.Multiplayer.MultiplayerSessionRoleTypes.h"
#include "Microsoft.Xbox.Services.Multiplayer.MultiplayerSessionRoleTypes.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Multiplayer::implementation
{
winrt::Windows::Foundation::Collections::IMapView<hstring,
                                                  winrt::Microsoft::Xbox::Services::Multiplayer::MultiplayerRoleType>
MultiplayerSessionRoleTypes::RoleTypes()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Multiplayer::implementation
