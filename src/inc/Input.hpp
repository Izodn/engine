#pragma once

#include <unordered_map>
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
		std::unordered_map<Input::Key, bool> m_Pressed;
		std::unordered_map<Input::Key, bool> m_Released;

	public:
		static Input* GetInstance();
		static void Clear();
		static void Press(Input::Key);
		static bool Pressed(Input::Key);
		static bool Released(Input::Key);
		static void Release(Input::Key);
		static double GetAxis(Input::Axis);

	public:
		Input();
};