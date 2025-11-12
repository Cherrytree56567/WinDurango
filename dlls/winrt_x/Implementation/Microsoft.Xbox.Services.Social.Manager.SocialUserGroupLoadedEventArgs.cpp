#include "Microsoft.Xbox.Services.Social.Manager.SocialUserGroupLoadedEventArgs.h"
#include "Microsoft.Xbox.Services.Social.Manager.SocialUserGroupLoadedEventArgs.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Social::Manager::implementation
{
winrt::Microsoft::Xbox::Services::Social::Manager::XboxSocialUserGroup SocialUserGroupLoadedEventArgs::SocialUserGroup()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Social::Manager::implementation
