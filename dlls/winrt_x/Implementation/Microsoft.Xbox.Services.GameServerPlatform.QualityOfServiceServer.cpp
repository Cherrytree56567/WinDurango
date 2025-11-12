#include "Microsoft.Xbox.Services.GameServerPlatform.QualityOfServiceServer.h"
#include "Microsoft.Xbox.Services.GameServerPlatform.QualityOfServiceServer.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::GameServerPlatform::implementation
{
hstring QualityOfServiceServer::ServerFullQualifiedDomainName()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
hstring QualityOfServiceServer::SecureDeviceAddressBase64()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
hstring QualityOfServiceServer::TargetLocation()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::GameServerPlatform::implementation
