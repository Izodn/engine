#include "Input.hpp"

#include "Logger.hpp"

Input* Input::Self()
{
	static Input* instance = new Input();
	return instance;
};

void Input::Sync()
{
	// If a pressed character is in released, remove it from pressed
	for (auto &elem : Self()->m_Released) {
		auto got = std::find(
			Self()->m_Pressed.begin(),
			Self()->m_Pressed.end(),
			elem
		);
		Self()->m_Pressed.erase(got);
	}
}

void Input::ClearPressed()
{
	Self()->m_Pressed.clear();
}

void Input::ClearReleased()
{
	Self()->m_Released.clear();
}

void Input::Clear()
{
	Self()->ClearPressed();
	Self()->ClearReleased();
}

double Input::GetAxis(Input::Axis axis)
{
	if (axis == Input::Axis::VERTICAL) {
		return Self()->m_CursorY;
	} else if (axis == Input::Axis::HORIZONTAL) {
		return Self()->m_CursorX;
	} else {
		Logger() << "Input::GetAxis() Unexpected axis requested\n";
		return 0.0f;
	}
}

void Input::SetAxis(double xPos, double yPos)
{
	Self()->m_CursorX = xPos;
	Self()->m_CursorY = yPos;
	//Logger() << "MousePos: (" << xPos << ", " << yPos << ")\n";
}

bool Input::Pressed(Input::Key key)
{
	auto got = std::find(
		Self()->m_Pressed.begin(),
		Self()->m_Pressed.end(),
		key
	);
	return (got != Self()->m_Pressed.end());
}

void Input::Press(Input::Key key)
{
	Self()->m_Pressed.push_back(key);
}

bool Input::Released(Input::Key key)
{
	auto got = std::find(
		Self()->m_Released.begin(),
		Self()->m_Released.end(),
		key
	);
	return (got != Self()->m_Released.end());
}

void Input::Release(Input::Key key)
{
	Self()->m_Released.push_back(key);
}