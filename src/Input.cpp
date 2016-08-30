#include "inc/Input.hpp"

Input::Input()
{

}

Input* Input::GetInstance()
{
	static Input instance;
	return &instance;
};

void Input::Clear()
{
	Input* instance = GetInstance();
	instance->m_Pressed.clear();
	instance->m_Released.clear();
}

double Input::GetAxis(Input::Axis axis)
{
	Input* instance = GetInstance();
	double delta = 0;

	if (axis == Input::Axis::VERTICAL) {

	} else if (axis == Input::Axis::HORIZONTAL) {

	} else {

	}

	return delta;
}

bool Input::Pressed(Input::Key key)
{
	Input* instance = GetInstance();
	return (instance->m_Pressed.find(key) != instance->m_Pressed.end());
}

void Input::Press(Input::Key key)
{
	Input* instance = GetInstance();
	instance->m_Pressed[key] = true;
}

bool Input::Released(Input::Key key)
{
	Input* instance = GetInstance();
	return (instance->m_Released.find(key) != instance->m_Released.end());
}

void Input::Release(Input::Key key)
{
	Input* instance = GetInstance();
	instance->m_Released[key] = true;
}