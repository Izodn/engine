#include "inc/Input.hpp"

Input::Input()
{

}

Input* Input::Self()
{
	static Input* instance = new Input();
	return instance;
};

void Input::Clear()
{
	Self()->m_Pressed.clear();
	Self()->m_Released.clear();
}

double Input::GetAxis(Input::Axis axis)
{
	double delta = 0;

	if (axis == Input::Axis::VERTICAL) {

	} else if (axis == Input::Axis::HORIZONTAL) {

	} else {

	}

	return delta;
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