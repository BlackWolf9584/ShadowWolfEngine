#pragma once

namespace Wolf
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
#define SW_KEY_SPACE           ::Wolf::Key::Space
#define SW_KEY_APOSTROPHE      ::Wolf::Key::Apostrophe    /* ' */
#define SW_KEY_COMMA           ::Wolf::Key::Comma         /* , */
#define SW_KEY_MINUS           ::Wolf::Key::Minus         /* - */
#define SW_KEY_PERIOD          ::Wolf::Key::Period        /* . */
#define SW_KEY_SLASH           ::Wolf::Key::Slash         /* / */
#define SW_KEY_0               ::Wolf::Key::D0
#define SW_KEY_1               ::Wolf::Key::D1
#define SW_KEY_2               ::Wolf::Key::D2
#define SW_KEY_3               ::Wolf::Key::D3
#define SW_KEY_4               ::Wolf::Key::D4
#define SW_KEY_5               ::Wolf::Key::D5
#define SW_KEY_6               ::Wolf::Key::D6
#define SW_KEY_7               ::Wolf::Key::D7
#define SW_KEY_8               ::Wolf::Key::D8
#define SW_KEY_9               ::Wolf::Key::D9
#define SW_KEY_SEMICOLON       ::Wolf::Key::Semicolon     /* ; */
#define SW_KEY_EQUAL           ::Wolf::Key::Equal         /* = */
#define SW_KEY_A               ::Wolf::Key::A
#define SW_KEY_B               ::Wolf::Key::B
#define SW_KEY_C               ::Wolf::Key::C
#define SW_KEY_D               ::Wolf::Key::D
#define SW_KEY_E               ::Wolf::Key::E
#define SW_KEY_F               ::Wolf::Key::F
#define SW_KEY_G               ::Wolf::Key::G
#define SW_KEY_H               ::Wolf::Key::H
#define SW_KEY_I               ::Wolf::Key::I
#define SW_KEY_J               ::Wolf::Key::J
#define SW_KEY_K               ::Wolf::Key::K
#define SW_KEY_L               ::Wolf::Key::L
#define SW_KEY_M               ::Wolf::Key::M
#define SW_KEY_N               ::Wolf::Key::N
#define SW_KEY_O               ::Wolf::Key::O
#define SW_KEY_P               ::Wolf::Key::P
#define SW_KEY_Q               ::Wolf::Key::Q
#define SW_KEY_R               ::Wolf::Key::R
#define SW_KEY_S               ::Wolf::Key::S
#define SW_KEY_T               ::Wolf::Key::T
#define SW_KEY_U               ::Wolf::Key::U
#define SW_KEY_V               ::Wolf::Key::V
#define SW_KEY_W               ::Wolf::Key::W
#define SW_KEY_X               ::Wolf::Key::X
#define SW_KEY_Y               ::Wolf::Key::Y
#define SW_KEY_Z               ::Wolf::Key::Z
#define SW_KEY_LEFT_BRACKET    ::Wolf::Key::LeftBracket   /* [ */
#define SW_KEY_BACKSLASH       ::Wolf::Key::Backslash     /* \ */
#define SW_KEY_RIGHT_BRACKET   ::Wolf::Key::RightBracket  /* ] */
#define SW_KEY_GRAVE_ACCENT    ::Wolf::Key::GraveAccent   /* ` */
#define SW_KEY_WORLD_1         ::Wolf::Key::World1        /* non-US #1 */
#define SW_KEY_WORLD_2         ::Wolf::Key::World2        /* non-US #2 */

/* Function keys */
#define SW_KEY_ESCAPE          ::Wolf::Key::Escape
#define SW_KEY_ENTER           ::Wolf::Key::Enter
#define SW_KEY_TAB             ::Wolf::Key::Tab
#define SW_KEY_BACKSPACE       ::Wolf::Key::Backspace
#define SW_KEY_INSERT          ::Wolf::Key::Insert
#define SW_KEY_DELETE          ::Wolf::Key::Delete
#define SW_KEY_RIGHT           ::Wolf::Key::Right
#define SW_KEY_LEFT            ::Wolf::Key::Left
#define SW_KEY_DOWN            ::Wolf::Key::Down
#define SW_KEY_UP              ::Wolf::Key::Up
#define SW_KEY_PAGE_UP         ::Wolf::Key::PageUp
#define SW_KEY_PAGE_DOWN       ::Wolf::Key::PageDown
#define SW_KEY_HOME            ::Wolf::Key::Home
#define SW_KEY_END             ::Wolf::Key::End
#define SW_KEY_CAPS_LOCK       ::Wolf::Key::CapsLock
#define SW_KEY_SCROLL_LOCK     ::Wolf::Key::ScrollLock
#define SW_KEY_NUM_LOCK        ::Wolf::Key::NumLock
#define SW_KEY_PRINT_SCREEN    ::Wolf::Key::PrintScreen
#define SW_KEY_PAUSE           ::Wolf::Key::Pause
#define SW_KEY_F1              ::Wolf::Key::F1
#define SW_KEY_F2              ::Wolf::Key::F2
#define SW_KEY_F3              ::Wolf::Key::F3
#define SW_KEY_F4              ::Wolf::Key::F4
#define SW_KEY_F5              ::Wolf::Key::F5
#define SW_KEY_F6              ::Wolf::Key::F6
#define SW_KEY_F7              ::Wolf::Key::F7
#define SW_KEY_F8              ::Wolf::Key::F8
#define SW_KEY_F9              ::Wolf::Key::F9
#define SW_KEY_F10             ::Wolf::Key::F10
#define SW_KEY_F11             ::Wolf::Key::F11
#define SW_KEY_F12             ::Wolf::Key::F12
#define SW_KEY_F13             ::Wolf::Key::F13
#define SW_KEY_F14             ::Wolf::Key::F14
#define SW_KEY_F15             ::Wolf::Key::F15
#define SW_KEY_F16             ::Wolf::Key::F16
#define SW_KEY_F17             ::Wolf::Key::F17
#define SW_KEY_F18             ::Wolf::Key::F18
#define SW_KEY_F19             ::Wolf::Key::F19
#define SW_KEY_F20             ::Wolf::Key::F20
#define SW_KEY_F21             ::Wolf::Key::F21
#define SW_KEY_F22             ::Wolf::Key::F22
#define SW_KEY_F23             ::Wolf::Key::F23
#define SW_KEY_F24             ::Wolf::Key::F24
#define SW_KEY_F25             ::Wolf::Key::F25

/* Keypad */
#define SW_KEY_KP_0            ::Wolf::Key::KP0
#define SW_KEY_KP_1            ::Wolf::Key::KP1
#define SW_KEY_KP_2            ::Wolf::Key::KP2
#define SW_KEY_KP_3            ::Wolf::Key::KP3
#define SW_KEY_KP_4            ::Wolf::Key::KP4
#define SW_KEY_KP_5            ::Wolf::Key::KP5
#define SW_KEY_KP_6            ::Wolf::Key::KP6
#define SW_KEY_KP_7            ::Wolf::Key::KP7
#define SW_KEY_KP_8            ::Wolf::Key::KP8
#define SW_KEY_KP_9            ::Wolf::Key::KP9
#define SW_KEY_KP_DECIMAL      ::Wolf::Key::KPDecimal
#define SW_KEY_KP_DIVIDE       ::Wolf::Key::KPDivide
#define SW_KEY_KP_MULTIPLY     ::Wolf::Key::KPMultiply
#define SW_KEY_KP_SUBTRACT     ::Wolf::Key::KPSubtract
#define SW_KEY_KP_ADD          ::Wolf::Key::KPAdd
#define SW_KEY_KP_ENTER        ::Wolf::Key::KPEnter
#define SW_KEY_KP_EQUAL        ::Wolf::Key::KPEqual

#define SW_KEY_LEFT_SHIFT      ::Wolf::Key::LeftShift
#define SW_KEY_LEFT_CONTROL    ::Wolf::Key::LeftControl
#define SW_KEY_LEFT_ALT        ::Wolf::Key::LeftAlt
#define SW_KEY_LEFT_SUPER      ::Wolf::Key::LeftSuper
#define SW_KEY_RIGHT_SHIFT     ::Wolf::Key::RightShift
#define SW_KEY_RIGHT_CONTROL   ::Wolf::Key::RightControl
#define SW_KEY_RIGHT_ALT       ::Wolf::Key::RightAlt
#define SW_KEY_RIGHT_SUPER     ::Wolf::Key::RightSuper
#define SW_KEY_MENU            ::Wolf::Key::Menu

// Mouse (TODO: move into separate file probably)
#define SW_MOUSE_BUTTON_LEFT    0
#define SW_MOUSE_BUTTON_RIGHT   1
#define SW_MOUSE_BUTTON_MIDDLE  2