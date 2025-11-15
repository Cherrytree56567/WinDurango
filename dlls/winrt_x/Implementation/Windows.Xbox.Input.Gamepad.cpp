#include "pch.h"
#include "Windows.h"
#include "Windows.Xbox.Input.GamepadReading.h"
#include "Windows.Xbox.Input.Gamepad.h"
#include "Windows.Xbox.Input.Gamepad.g.cpp"
#include "Windows.Xbox.System.User.h"

#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.Input.h>
#include <windowsx.h>
#include <Xinput.h>

namespace winrt::Windows::Xbox::Input::implementation
{
	Foundation::Collections::IVectorView<IGamepad> Gamepad::Gamepads()
	{
		if (staticGamepads == Foundation::Collections::IVector<IGamepad>(nullptr) || staticGamepads.Size() == 0) {
			staticGamepads = winrt::single_threaded_vector<IGamepad>();
			
			LOG_INFO_W(L"Gamepad || Gamepads Queried!\n");
		   
			for (DWORD gamepad = 0; gamepad < XUSER_MAX_COUNT; gamepad++)
			{
				XINPUT_CAPABILITIES capabilities;
				if (XInputGetCapabilities(gamepad, XINPUT_FLAG_GAMEPAD, &capabilities) == ERROR_SUCCESS)
				{
					wprintf(L"Gamepad || Gamepad %d Created!\n", gamepad);
					IGamepad newGamepad = winrt::make<Gamepad>(gamepad);
					staticGamepads.Append(newGamepad);
				}
			}
		}

		if (staticGamepads.Size() == 0) {
			wprintf(L"Gamepad || No Gamepads Found!\n");

			const IGamepad dummyGamepad = winrt::make<Gamepad>(0);

			staticGamepads.Append(dummyGamepad);
		}

		const HWND hwnd = GetFocus();

		ShowCursor(FALSE);

		RECT rc;

		GetClientRect(hwnd, &rc);

		POINT tl = { rc.left, rc.top };
		POINT br = { rc.right, rc.bottom };

		MapWindowPoints(hwnd, nullptr, &tl, 1);
		MapWindowPoints(hwnd, nullptr, &br, 1);

		const RECT screenRect = { tl.x, tl.y, br.x, br.y };

		ClipCursor(&screenRect);
		ShowCursor(FALSE);

		return staticGamepads.GetView();
	}

	event_token Gamepad::GamepadAdded(Foundation::EventHandler<GamepadAddedEventArgs> const& handler)
	{
		LOG_INFO_W(L"Gamepad || Gamepad Added!\n");

		LOG_WARNING("Gamepad || GamepadAdded event is not implemented, returning empty token.");
		
		return {};
	}

	void Gamepad::GamepadAdded(event_token const& token) noexcept
	{
		LOG_INFO_W(L"Gamepad || Gamepad Added!\n");

		LOG_NOT_IMPLEMENTED();

		throw hresult_not_implemented();
	}

	event_token Gamepad::GamepadRemoved(Foundation::EventHandler<GamepadRemovedEventArgs> const& handler)
	{
		LOG_INFO_W(L"Gamepad || Gamepad Removed!\n");

		LOG_NOT_IMPLEMENTED();

		return {};
	}

	void Gamepad::GamepadRemoved(event_token const& token) noexcept
	{
		LOG_INFO_W(L"Gamepad || Gamepad Removed!\n");

		LOG_NOT_IMPLEMENTED();

		throw hresult_not_implemented();
	}

	uint64_t Gamepad::Id()
	{
		LOG_INFO_W(L"Gamepad || Gamepad ID (%d) Queried!\n", m_id);

		return m_id;
	}

	hstring Gamepad::Type()
	{
		return L"Windows.Xbox.Input.Gamepad";
	}

	System::User Gamepad::User()
	{
		LOG_INFO_W(L"Gamepad || User Queried!\n");

		return System::implementation::User::Users().GetAt(Id());
	}

	INavigationReading Gamepad::GetNavigationReading()
	{
		LOG_NOT_IMPLEMENTED();

		throw hresult_not_implemented();
	}

	RawNavigationReading Gamepad::GetRawNavigationReading()
	{
		auto dummyNavigationReading = RawNavigationReading();

		dummyNavigationReading.Timestamp = GetTickCount64();
		dummyNavigationReading.Buttons |= NavigationButtons::Up;

		return dummyNavigationReading;
	}

	event_token Gamepad::NavigationReadingChanged(Foundation::TypedEventHandler<NavigationController, INavigationReadingChangedEventArgs> const& handler)
	{
		LOG_NOT_IMPLEMENTED();

		throw hresult_not_implemented();
	}

	void Gamepad::NavigationReadingChanged(event_token const& token) noexcept
	{
		LOG_NOT_IMPLEMENTED();

		throw hresult_not_implemented();
	}

	void Gamepad::SetVibration(GamepadVibration const& value)
	{
		XINPUT_VIBRATION vibration;
		ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
		vibration.wLeftMotorSpeed = static_cast<WORD>(value.LeftMotorLevel * 65535);
		vibration.wRightMotorSpeed = static_cast<WORD>(value.RightMotorLevel * 65535);
		XInputSetState(m_id, &vibration);
	}

	IGamepadReading Gamepad::GetCurrentReading()
	{
		return winrt::make<GamepadReading>(GetRawCurrentReading());
	}

	RawGamepadReading Gamepad::GetRawCurrentReading()
	{

		XINPUT_STATE xiState;
		ZeroMemory(&xiState, sizeof(XINPUT_STATE));
		reading = {};

		if (const DWORD result = XInputGetState(m_id, &xiState); result == ERROR_SUCCESS)
		{
			// Debug logging - remove after testing
			if (xiState.Gamepad.wButtons != 0)
			{
				LOG_INFO_W(L"Gamepad || Controller %d - Button mask: 0x%04X\n", m_id, xiState.Gamepad.wButtons);
			}

			for (int i = 0; i < ARRAYSIZE(gamepadButtons); i++)
			{
				if (xiState.Gamepad.wButtons & gamepadButtons[ i ].first)
				{
					reading.Buttons |= gamepadButtons[ i ].second;

					// Debug: Log when Start button is detected
					if (gamepadButtons[ i ].first == XINPUT_GAMEPAD_START)
					{
						LOG_INFO_W(L"Gamepad || START BUTTON DETECTED!\n");
					}
				}
			}

			reading.LeftTrigger = xiState.Gamepad.bLeftTrigger / 255.f;
			reading.RightTrigger = xiState.Gamepad.bRightTrigger / 255.f;
			reading.LeftThumbstickX = xiState.Gamepad.sThumbLX / 32768.f;
			reading.LeftThumbstickY = xiState.Gamepad.sThumbLY / 32768.f;
			reading.RightThumbstickX = xiState.Gamepad.sThumbRX / 32768.f;
			reading.RightThumbstickY = xiState.Gamepad.sThumbRY / 32768.f;
		}
		else
		{
			LOG_WARNING_W(L"Gamepad || XInputGetState failed for controller %d with error: %d\n", m_id, result);
		}

		float lx = 0.0f;
		float ly = 0.0f;

		for (int i = 0; i < ARRAYSIZE(keyboardButtons); i++)
		{
			if (GetAsyncKeyState(keyboardButtons[i].first))
				reading.Buttons |= keyboardButtons[i].second;

			if (GetAsyncKeyState(config.GetData().movementThumbY) & 0x8000)
				ly = 1.0f;

			if (GetAsyncKeyState(config.GetData().movementThumbXM) & 0x8000)
				lx = -1.0f;

			if (GetAsyncKeyState(config.GetData().movementThumbYM) & 0x8000)
				ly = -1.0;

			if (GetAsyncKeyState(config.GetData().movementThumbX) & 0x8000)
				lx = 1.0f;
		}

		lx = std::clamp(lx, -1.0f, 1.0f);
		ly = std::clamp(ly, -1.0f, 1.0f);

		if (lx != 0.0f || ly != 0.0f) {
			if (config.GetData().movementStick == "Left") {
				reading.LeftThumbstickX = lx;
				reading.LeftThumbstickY = ly;
			} else if (config.GetData().movementStick == "Right") {
				reading.RightThumbstickX = lx;
				reading.RightThumbstickY = ly;
			}
		}        

		if (GetAsyncKeyState(config.GetData().rTrigger) & 0x8000)
			reading.RightTrigger = 1.0f;

		if (GetAsyncKeyState(config.GetData().lTrigger) & 0x8000)
			reading.LeftTrigger = 1.0f;

		POINT pos;
		GetCursorPos(&pos);

		if (firstFrame) {
			prev = pos;
			firstFrame = false;
		}

		const int dx = pos.x - prev.x;
		const int dy = pos.y - prev.y;

		deltaSumX += dx;
		deltaSumY += dy;
		prev = pos;

		const int centerX = GetSystemMetrics(SM_CXSCREEN) / 2;
		const int centerY = GetSystemMetrics(SM_CYSCREEN) / 2;

		SetCursorPos(centerX, centerY);

		prev.x = centerX;
		prev.y = centerY;
		
		auto sign = [](float v) { return (v > 0) - (v < 0); };
		
		float x = -std::exp((-1.0f / 5.0f) * std::abs(deltaSumX)) + 1.0f;
		float y = -std::exp((-1.0f / 5.0f) * std::abs(deltaSumY)) + 1.0f;

		x *= sign(deltaSumX);
		y *= -sign(deltaSumY);

		if (x != 0 || y != 0) {
			if (config.GetData().mouseStick == "Right") {
				reading.RightThumbstickX = std::clamp(x, -1.0f, 1.0f);
				reading.RightThumbstickY = std::clamp(y, -1.0f, 1.0f);
			}
			else if (config.GetData().mouseStick == "Left") {
				reading.LeftThumbstickX = std::clamp(x, -1.0f, 1.0f);
				reading.LeftThumbstickY = std::clamp(y, -1.0f, 1.0f);
			}
		}

		deltaSumX = 0.0f;
		deltaSumY = 0.0f;

		return reading;
	}

	event_token Gamepad::ReadingChanged(Foundation::TypedEventHandler<Input::Gamepad, IGamepadReadingChangedEventArgs> const& handler)
	{
		LOG_NOT_IMPLEMENTED();

		throw hresult_not_implemented();
	}

	void Gamepad::ReadingChanged(event_token const& token) noexcept
	{
		LOG_NOT_IMPLEMENTED();

		throw hresult_not_implemented();
	}

	bool Gamepad::IsTrusted()
	{
		return true;
	}
}