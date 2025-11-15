#pragma once
#include "Windows.Xbox.Input.Gamepad.g.h"

#include "WinDurangoConfig.h"

#include <Xinput.h>
#include <windows.h>
#include <winrt/Windows.UI.Core.h>

namespace winrt::Windows::Xbox::Input::implementation
{
    struct Gamepad : GamepadT<Gamepad>
    {
        Gamepad() = default;
        Gamepad(uint64_t id) : m_id(id), config(WinDurangoConfig::Instance()) {
            keyboardButtons[0].first = config.GetData().up;
            keyboardButtons[1].first = config.GetData().down;
            keyboardButtons[2].first = config.GetData().left;
            keyboardButtons[3].first = config.GetData().right;
            keyboardButtons[4].first = config.GetData().menu;
            keyboardButtons[5].first = config.GetData().view;
            keyboardButtons[6].first = config.GetData().lThumb;
            keyboardButtons[7].first = config.GetData().rThumb;
            keyboardButtons[8].first = config.GetData().lShoulder;
            keyboardButtons[9].first = config.GetData().rShoulder;
            keyboardButtons[10].first = config.GetData().a;
            keyboardButtons[11].first = config.GetData().b;
            keyboardButtons[12].first = config.GetData().x;
            keyboardButtons[13].first = config.GetData().y;
        }

        static Foundation::Collections::IVectorView<IGamepad> Gamepads();
        static event_token GamepadAdded(Foundation::EventHandler<GamepadAddedEventArgs> const& handler);
        static void GamepadAdded(event_token const& token) noexcept;
        static event_token GamepadRemoved(Foundation::EventHandler<GamepadRemovedEventArgs> const& handler);
        static void GamepadRemoved(event_token const& token) noexcept;
        uint64_t Id();
        hstring Type();
        System::User User();
        INavigationReading GetNavigationReading();
        RawNavigationReading GetRawNavigationReading();
        event_token NavigationReadingChanged(Foundation::TypedEventHandler<NavigationController, INavigationReadingChangedEventArgs> const& handler);
        void NavigationReadingChanged(event_token const& token) noexcept;
        void SetVibration(GamepadVibration const& value);
        IGamepadReading GetCurrentReading();
        RawGamepadReading GetRawCurrentReading();
        event_token ReadingChanged(Foundation::TypedEventHandler<Input::Gamepad, IGamepadReadingChangedEventArgs> const& handler);
        void ReadingChanged(event_token const& token) noexcept;
        bool IsTrusted();
        inline static Foundation::Collections::IVector<IGamepad> staticGamepads = { nullptr };
        uint64_t m_id{ 0 };
        RawGamepadReading reading = {};
        POINT prev{ 0, 0 };
        float deltaSumX = 0.0f;
        float deltaSumY = 0.0f;
        bool firstFrame = true;
        WinDurangoConfig& config;

        inline static std::pair<WORD, GamepadButtons> const gamepadButtons[] =
        {
            { XINPUT_GAMEPAD_DPAD_UP, GamepadButtons::DPadUp },
            { XINPUT_GAMEPAD_DPAD_DOWN, GamepadButtons::DPadDown },
            { XINPUT_GAMEPAD_DPAD_LEFT, GamepadButtons::DPadLeft },
            { XINPUT_GAMEPAD_DPAD_RIGHT, GamepadButtons::DPadRight },
            { XINPUT_GAMEPAD_START, GamepadButtons::Menu },
            { XINPUT_GAMEPAD_BACK, GamepadButtons::View },
            { XINPUT_GAMEPAD_LEFT_THUMB, GamepadButtons::LeftThumbstick },
            { XINPUT_GAMEPAD_RIGHT_THUMB, GamepadButtons::RightThumbstick },
            { XINPUT_GAMEPAD_LEFT_SHOULDER, GamepadButtons::LeftShoulder },
            { XINPUT_GAMEPAD_RIGHT_SHOULDER, GamepadButtons::RightShoulder },
            { XINPUT_GAMEPAD_A, GamepadButtons::A },
            { XINPUT_GAMEPAD_B, GamepadButtons::B },
            { XINPUT_GAMEPAD_X, GamepadButtons::X },
            { XINPUT_GAMEPAD_Y, GamepadButtons::Y },
        };
        
        inline static std::pair<WORD, GamepadButtons> keyboardButtons[] =
        {
            { VK_UP, GamepadButtons::DPadUp },
            { VK_DOWN, GamepadButtons::DPadDown },
            { VK_LEFT, GamepadButtons::DPadLeft },
            { VK_RIGHT, GamepadButtons::DPadRight },
            { VK_RETURN, GamepadButtons::Menu },
            { VK_ESCAPE, GamepadButtons::View },
            { VK_RSHIFT, GamepadButtons::LeftThumbstick },
            { VK_LSHIFT, GamepadButtons::RightThumbstick },
            { VK_LCONTROL, GamepadButtons::LeftShoulder },
            { VK_RCONTROL, GamepadButtons::RightShoulder },
            { VK_SPACE, GamepadButtons::A },
            { 'Q', GamepadButtons::B},
            { 'R', GamepadButtons::X},
            { 'E', GamepadButtons::Y},
        };
    };
}

namespace winrt::Windows::Xbox::Input::factory_implementation
{
    struct Gamepad : GamepadT<Gamepad, implementation::Gamepad>
    {
    };
}