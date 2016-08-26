#include "inc/InputHandler.hpp"

InputHandler::InputHandler()
{

}

uint64_t InputHandler::GetKeyCode(std::string keyName)
{
	// Return the matched key code

	// For now, return 0.
	return 0;
}

double InputHandler::GetAxis(std::string axis)
{
	double delta = 0;

	if (axis == "Vertical") {

	} else if (axis == "Horizontal") {

	} else {

	}

	return delta;
}

bool InputHandler::Pressed(uint64_t keyCode)
{
	// Return whether or not the key was pressed since the last update

	// For now, return false.
	return false;
}

bool InputHandler::Released(uint64_t keyCode)
{
	// Return whether or not the key was released since the last update

	// For now, return false.
	return false;
}