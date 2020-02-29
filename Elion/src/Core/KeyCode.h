#pragma once
// using for uint16_t
namespace Elion
{
	typedef enum class KeyCode : uint16_t
	{
		
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

	
}


#define KEY_SPACE           ::Elion::Key::Space
#define KEY_APOSTROPHE      ::Elion::Key::Apostrophe    /* ' */
#define KEY_COMMA           ::Elion::Key::Comma         /* , */
#define KEY_MINUS           ::Elion::Key::Minus         /* - */
#define KEY_PERIOD          ::Elion::Key::Period        /* . */
#define KEY_SLASH           ::Elion::Key::Slash         /* / */
#define KEY_0               ::Elion::Key::D0
#define KEY_1               ::Elion::Key::D1
#define KEY_2               ::Elion::Key::D2
#define KEY_3               ::Elion::Key::D3
#define KEY_4               ::Elion::Key::D4
#define KEY_5               ::Elion::Key::D5
#define KEY_6               ::Elion::Key::D6
#define KEY_7               ::Elion::Key::D7
#define KEY_8               ::Elion::Key::D8
#define KEY_9               ::Elion::Key::D9
#define KEY_SEMICOLON       ::Elion::Key::Semicolon     /* ; */
#define KEY_EQUAL           ::Elion::Key::Equal         /* = */
#define KEY_A               ::Elion::Key::A
#define KEY_B               ::Elion::Key::B
#define KEY_C               ::Elion::Key::C
#define KEY_D               ::Elion::Key::D
#define KEY_E               ::Elion::Key::E
#define KEY_F               ::Elion::Key::F
#define KEY_G               ::Elion::Key::G
#define KEY_H               ::Elion::Key::H
#define KEY_I               ::Elion::Key::I
#define KEY_J               ::Elion::Key::J
#define KEY_K               ::Elion::Key::K
#define KEY_L               ::Elion::Key::L
#define KEY_M               ::Elion::Key::M
#define KEY_N               ::Elion::Key::N
#define KEY_O               ::Elion::Key::O
#define KEY_P               ::Elion::Key::P
#define KEY_Q               ::Elion::Key::Q
#define KEY_R               ::Elion::Key::R
#define KEY_S               ::Elion::Key::S
#define KEY_T               ::Elion::Key::T
#define KEY_U               ::Elion::Key::U
#define KEY_V               ::Elion::Key::V
#define KEY_W               ::Elion::Key::W
#define KEY_X               ::Elion::Key::X
#define KEY_Y               ::Elion::Key::Y
#define KEY_Z               ::Elion::Key::Z
#define KEY_LEFT_BRACKET    ::Elion::Key::LeftBracket   /* [ */
#define KEY_BACKSLASH       ::Elion::Key::Backslash     /* \ */
#define KEY_RIGHT_BRACKET   ::Elion::Key::RightBracket  /* ] */
#define KEY_GRAVE_ACCENT    ::Elion::Key::GraveAccent   /* ` */
#define KEY_WORLD_1         ::Elion::Key::World1        /* non-US #1 */
#define KEY_WORLD_2         ::Elion::Key::World2        /* non-US #2 */

/* Function keys */
#define KEY_ESCAPE          ::Elion::Key::Escape
#define KEY_ENTER           ::Elion::Key::Enter
#define KEY_TAB             ::Elion::Key::Tab
#define KEY_BACKSPACE       ::Elion::Key::Backspace
#define KEY_INSERT          ::Elion::Key::Insert
#define KEY_DELETE          ::Elion::Key::Delete
#define KEY_RIGHT           ::Elion::Key::Right
#define KEY_LEFT            ::Elion::Key::Left
#define KEY_DOWN            ::Elion::Key::Down
#define KEY_UP              ::Elion::Key::Up
#define KEY_PAGE_UP         ::Elion::Key::PageUp
#define KEY_PAGE_DOWN       ::Elion::Key::PageDown
#define KEY_HOME            ::Elion::Key::Home
#define KEY_END             ::Elion::Key::End
#define KEY_CAPS_LOCK       ::Elion::Key::CapsLock
#define KEY_SCROLL_LOCK     ::Elion::Key::ScrollLock
#define KEY_NUM_LOCK        ::Elion::Key::NumLock
#define KEY_PRINT_SCREEN    ::Elion::Key::PrintScreen
#define KEY_PAUSE           ::Elion::Key::Pause
#define KEY_F1              ::Elion::Key::F1
#define KEY_F2              ::Elion::Key::F2
#define KEY_F3              ::Elion::Key::F3
#define KEY_F4              ::Elion::Key::F4
#define KEY_F5              ::Elion::Key::F5
#define KEY_F6              ::Elion::Key::F6
#define KEY_F7              ::Elion::Key::F7
#define KEY_F8              ::Elion::Key::F8
#define KEY_F9              ::Elion::Key::F9
#define KEY_F10             ::Elion::Key::F10
#define KEY_F11             ::Elion::Key::F11
#define KEY_F12             ::Elion::Key::F12
#define KEY_F13             ::Elion::Key::F13
#define KEY_F14             ::Elion::Key::F14
#define KEY_F15             ::Elion::Key::F15
#define KEY_F16             ::Elion::Key::F16
#define KEY_F17             ::Elion::Key::F17
#define KEY_F18             ::Elion::Key::F18
#define KEY_F19             ::Elion::Key::F19
#define KEY_F20             ::Elion::Key::F20
#define KEY_F21             ::Elion::Key::F21
#define KEY_F22             ::Elion::Key::F22
#define KEY_F23             ::Elion::Key::F23
#define KEY_F24             ::Elion::Key::F24
#define KEY_F25             ::Elion::Key::F25

/* Keypad */
#define KEY_KP_0            ::Elion::Key::KP0
#define KEY_KP_1            ::Elion::Key::KP1
#define KEY_KP_2            ::Elion::Key::KP2
#define KEY_KP_3            ::Elion::Key::KP3
#define KEY_KP_4            ::Elion::Key::KP4
#define KEY_KP_5            ::Elion::Key::KP5
#define KEY_KP_6            ::Elion::Key::KP6
#define KEY_KP_7            ::Elion::Key::KP7
#define KEY_KP_8            ::Elion::Key::KP8
#define KEY_KP_9            ::Elion::Key::KP9
#define KEY_KP_DECIMAL      ::Elion::Key::KPDecimal
#define KEY_KP_DIVIDE       ::Elion::Key::KPDivide
#define KEY_KP_MULTIPLY     ::Elion::Key::KPMultiply
#define KEY_KP_SUBTRACT     ::Elion::Key::KPSubtract
#define KEY_KP_ADD          ::Elion::Key::KPAdd
#define KEY_KP_ENTER        ::Elion::Key::KPEnter
#define KEY_KP_EQUAL        ::Elion::Key::KPEqual

#define KEY_LEFT_SHIFT      ::Elion::Key::LeftShift
#define KEY_LEFT_CONTROL    ::Elion::Key::LeftControl
#define KEY_LEFT_ALT        ::Elion::Key::LeftAlt
#define KEY_LEFT_SUPER      ::Elion::Key::LeftSuper
#define KEY_RIGHT_SHIFT     ::Elion::Key::RightShift
#define KEY_RIGHT_CONTROL   ::Elion::Key::RightControl
#define KEY_RIGHT_ALT       ::Elion::Key::RightAlt
#define KEY_RIGHT_SUPER     ::Elion::Key::RightSuper
#define KEY_MENU            ::Elion::Key::Menu