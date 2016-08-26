#pragma once

#include <string>

class InputHandler
{
	public:
		InputHandler();
		uint64_t GetKeyCode(std::string);
		double GetAxis(std::string);
		bool Pressed(uint64_t);
		bool Released(uint64_t);
};