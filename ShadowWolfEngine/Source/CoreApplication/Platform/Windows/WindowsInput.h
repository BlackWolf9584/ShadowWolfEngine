#pragma once
#include "CoreApplication/Core/InputCore/Input.h"

namespace SW
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode);

		virtual bool IsMouseButtonPressedImpl(int button);
		virtual float GetMouseXImpl();
		virtual float GetMouseYImpl();
	};
}