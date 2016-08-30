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
			MOUSE_ONE,
			MOUSE_TWO,
			KEY_SPACE
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