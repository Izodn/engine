#pragma once

#include "../Input.hpp"

class Input;

class Component
{
	public:
		Component();
		virtual void Start() = 0;
		virtual void Update() = 0;
};