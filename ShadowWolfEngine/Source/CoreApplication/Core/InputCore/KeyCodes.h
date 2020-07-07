#pragma once

namespace SW
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define SW_KEY_SPACE           ::SW::Key::Space
#define SW_KEY_APOSTROPHE      ::SW::Key::Apostrophe    /* ' */
#define SW_KEY_COMMA           ::SW::Key::Comma         /* , */
#define SW_KEY_MINUS           ::SW::Key::Minus         /* - */
#define SW_KEY_PERIOD          ::SW::Key::Period        /* . */
#define SW_KEY_SLASH           ::SW::Key::Slash         /* / */
#define SW_KEY_0               ::SW::Key::D0
#define SW_KEY_1               ::SW::Key::D1
#define SW_KEY_2               ::SW::Key::D2
#define SW_KEY_3               ::SW::Key::D3
#define SW_KEY_4               ::SW::Key::D4
#define SW_KEY_5               ::SW::Key::D5
#define SW_KEY_6               ::SW::Key::D6
#define SW_KEY_7               ::SW::Key::D7
#define SW_KEY_8               ::SW::Key::D8
#define SW_KEY_9               ::SW::Key::D9
#define SW_KEY_SEMICOLON       ::SW::Key::Semicolon     /* ; */
#define SW_KEY_EQUAL           ::SW::Key::Equal         /* = */
#define SW_KEY_A               ::SW::Key::A
#define SW_KEY_B               ::SW::Key::B
#define SW_KEY_C               ::SW::Key::C
#define SW_KEY_D               ::SW::Key::D
#define SW_KEY_E               ::SW::Key::E
#define SW_KEY_F               ::SW::Key::F
#define SW_KEY_G               ::SW::Key::G
#define SW_KEY_H               ::SW::Key::H
#define SW_KEY_I               ::SW::Key::I
#define SW_KEY_J               ::SW::Key::J
#define SW_KEY_K               ::SW::Key::K
#define SW_KEY_L               ::SW::Key::L
#define SW_KEY_M               ::SW::Key::M
#define SW_KEY_N               ::SW::Key::N
#define SW_KEY_O               ::SW::Key::O
#define SW_KEY_P               ::SW::Key::P
#define SW_KEY_Q               ::SW::Key::Q
#define SW_KEY_R               ::SW::Key::R
#define SW_KEY_S               ::SW::Key::S
#define SW_KEY_T               ::SW::Key::T
#define SW_KEY_U               ::SW::Key::U
#define SW_KEY_V               ::SW::Key::V
#define SW_KEY_W               ::SW::Key::W
#define SW_KEY_X               ::SW::Key::X
#define SW_KEY_Y               ::SW::Key::Y
#define SW_KEY_Z               ::SW::Key::Z
#define SW_KEY_LEFT_BRACKET    ::SW::Key::LeftBracket   /* [ */
#define SW_KEY_BACKSLASH       ::SW::Key::Backslash     /* \ */
#define SW_KEY_RIGHT_BRACKET   ::SW::Key::RightBracket  /* ] */
#define SW_KEY_GRAVE_ACCENT    ::SW::Key::GraveAccent   /* ` */
#define SW_KEY_WORLD_1         ::SW::Key::World1        /* non-US #1 */
#define SW_KEY_WORLD_2         ::SW::Key::World2        /* non-US #2 */

/* Function keys */
#define SW_KEY_ESCAPE          ::SW::Key::Escape
#define SW_KEY_ENTER           ::SW::Key::Enter
#define SW_KEY_TAB             ::SW::Key::Tab
#define SW_KEY_BACKSPACE       ::SW::Key::Backspace
#define SW_KEY_INSERT          ::SW::Key::Insert
#define SW_KEY_DELETE          ::SW::Key::Delete
#define SW_KEY_RIGHT           ::SW::Key::Right
#define SW_KEY_LEFT            ::SW::Key::Left
#define SW_KEY_DOWN            ::SW::Key::Down
#define SW_KEY_UP              ::SW::Key::Up
#define SW_KEY_PAGE_UP         ::SW::Key::PageUp
#define SW_KEY_PAGE_DOWN       ::SW::Key::PageDown
#define SW_KEY_HOME            ::SW::Key::Home
#define SW_KEY_END             ::SW::Key::End
#define SW_KEY_CAPS_LOCK       ::SW::Key::CapsLock
#define SW_KEY_SCROLL_LOCK     ::SW::Key::ScrollLock
#define SW_KEY_NUM_LOCK        ::SW::Key::NumLock
#define SW_KEY_PRINT_SCREEN    ::SW::Key::PrintScreen
#define SW_KEY_PAUSE           ::SW::Key::Pause
#define SW_KEY_F1              ::SW::Key::F1
#define SW_KEY_F2              ::SW::Key::F2
#define SW_KEY_F3              ::SW::Key::F3
#define SW_KEY_F4              ::SW::Key::F4
#define SW_KEY_F5              ::SW::Key::F5
#define SW_KEY_F6              ::SW::Key::F6
#define SW_KEY_F7              ::SW::Key::F7
#define SW_KEY_F8              ::SW::Key::F8
#define SW_KEY_F9              ::SW::Key::F9
#define SW_KEY_F10             ::SW::Key::F10
#define SW_KEY_F11             ::SW::Key::F11
#define SW_KEY_F12             ::SW::Key::F12
#define SW_KEY_F13             ::SW::Key::F13
#define SW_KEY_F14             ::SW::Key::F14
#define SW_KEY_F15             ::SW::Key::F15
#define SW_KEY_F16             ::SW::Key::F16
#define SW_KEY_F17             ::SW::Key::F17
#define SW_KEY_F18             ::SW::Key::F18
#define SW_KEY_F19             ::SW::Key::F19
#define SW_KEY_F20             ::SW::Key::F20
#define SW_KEY_F21             ::SW::Key::F21
#define SW_KEY_F22             ::SW::Key::F22
#define SW_KEY_F23             ::SW::Key::F23
#define SW_KEY_F24             ::SW::Key::F24
#define SW_KEY_F25             ::SW::Key::F25

/* Keypad */
#define SW_KEY_KP_0            ::SW::Key::KP0
#define SW_KEY_KP_1            ::SW::Key::KP1
#define SW_KEY_KP_2            ::SW::Key::KP2
#define SW_KEY_KP_3            ::SW::Key::KP3
#define SW_KEY_KP_4            ::SW::Key::KP4
#define SW_KEY_KP_5            ::SW::Key::KP5
#define SW_KEY_KP_6            ::SW::Key::KP6
#define SW_KEY_KP_7            ::SW::Key::KP7
#define SW_KEY_KP_8            ::SW::Key::KP8
#define SW_KEY_KP_9            ::SW::Key::KP9
#define SW_KEY_KP_DECIMAL      ::SW::Key::KPDecimal
#define SW_KEY_KP_DIVIDE       ::SW::Key::KPDivide
#define SW_KEY_KP_MULTIPLY     ::SW::Key::KPMultiply
#define SW_KEY_KP_SUBTRACT     ::SW::Key::KPSubtract
#define SW_KEY_KP_ADD          ::SW::Key::KPAdd
#define SW_KEY_KP_ENTER        ::SW::Key::KPEnter
#define SW_KEY_KP_EQUAL        ::SW::Key::KPEqual

#define SW_KEY_LEFT_SHIFT      ::SW::Key::LeftShift
#define SW_KEY_LEFT_CONTROL    ::SW::Key::LeftControl
#define SW_KEY_LEFT_ALT        ::SW::Key::LeftAlt
#define SW_KEY_LEFT_SUPER      ::SW::Key::LeftSuper
#define SW_KEY_RIGHT_SHIFT     ::SW::Key::RightShift
#define SW_KEY_RIGHT_CONTROL   ::SW::Key::RightControl
#define SW_KEY_RIGHT_ALT       ::SW::Key::RightAlt
#define SW_KEY_RIGHT_SUPER     ::SW::Key::RightSuper
#define SW_KEY_MENU            ::SW::Key::Menu

// Mouse (TODO: move into separate file probably)
#define SW_MOUSE_BUTTON_LEFT    0
#define SW_MOUSE_BUTTON_RIGHT   1
#define SW_MOUSE_BUTTON_MIDDLE  2
