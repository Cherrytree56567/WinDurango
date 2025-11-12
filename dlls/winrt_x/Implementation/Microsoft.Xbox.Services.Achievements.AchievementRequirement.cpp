#include "Microsoft.Xbox.Services.Achievements.AchievementRequirement.h"
#include "Microsoft.Xbox.Services.Achievements.AchievementRequirement.g.cpp"
#include "pch.h"

namespace winrt::Microsoft::Xbox::Services::Achievements::implementation
{
hstring AchievementRequirement::Id()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
hstring AchievementRequirement::CurrentProgressValue()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
hstring AchievementRequirement::TargetProgressValue()
{
    LOG_NOT_IMPLEMENTED();
    throw hresult_not_implemented();
}
} // namespace winrt::Microsoft::Xbox::Services::Achievements::implementation
