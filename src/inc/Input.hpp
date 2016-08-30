#pragma once

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

class Input
{
	public:
		enum Key
		{
			// Mouse buttons
			MOUSE_ONE,
			MOUSE_TWO,

			// Keyboard buttons
			KEY_LCTRL,
			KEY_LALT,
			KEY_LSHIFT,
			KEY_SPACE,
			KEY_0,
			KEY_1,
			KEY_2,
			KEY_3,
			KEY_4,
			KEY_5,
			KEY_6,
			KEY_7,
			KEY_8,
			KEY_9,
			KEY_A,
			KEY_B,
			KEY_C,
			KEY_D,
			KEY_E,
			KEY_F,
			KEY_G,
			KEY_H,
			KEY_I,
			KEY_J,
			KEY_K,
			KEY_L,
			KEY_M,
			KEY_N,
			KEY_O,
			KEY_P,
			KEY_Q,
			KEY_R,
			KEY_S,
			KEY_T,
			KEY_U,
			KEY_V,
			KEY_W,
			KEY_X,
			KEY_Y,
			KEY_Z
		};

		enum Axis
		{
			VERTICAL,
			HORIZONTAL
		};

	private:
		std::vector<Input::Key> m_Pressed;
		std::vector<Input::Key> m_Released;

	public:
		static Input* Self();
		static void Clear();
		static void Press(Input::Key);
		static bool Pressed(Input::Key);
		static bool Released(Input::Key);
		static void Release(Input::Key);
		static double GetAxis(Input::Axis);

	public:
		Input();
};