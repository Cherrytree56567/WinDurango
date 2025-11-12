#include "Windows.Xbox.Networking.SecureDeviceAssociationIncomingEventArgs.h"
#include "Windows.Xbox.Networking.SecureDeviceAssociationIncomingEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
winrt::Windows::Xbox::Networking::SecureDeviceAssociation SecureDeviceAssociationIncomingEventArgs::Association()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Windows::Xbox::Networking::implementation
