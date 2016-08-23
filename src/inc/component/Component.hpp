#pragma once

#include "../InputHandler.hpp"

class Component
{
	private:
		InputHandler* m_InputHandler;

	public:
		Component();
		InputHandler* Input();
		virtual void Start() = 0;
		virtual void Update() = 0;
};