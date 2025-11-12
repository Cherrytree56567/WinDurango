#include "Windows.Xbox.UI.AccountPickerResult.h"
#include "Windows.Xbox.UI.AccountPickerResult.g.cpp"
#include "pch.h"

namespace winrt::Windows::Xbox::UI::implementation
{
winrt::Windows::Xbox::System::IUser AccountPickerResult::User()
{
    uint64_t count = signedInUsersCount + 1;
    return System::User::Users().GetAt(count);
}
} // namespace winrt::Windows::Xbox::UI::implementation
