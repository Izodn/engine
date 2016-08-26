#pragma once

#include <iostream>
#include <string>

#include "Renderer.hpp"
#include "OpenGLRenderer.hpp"

class Window
{
	private:
		Renderer* m_Renderer = NULL;

	public:
		Window(uint64_t, uint64_t, std::string);
		void ChangeRenderer(Renderer::Type);
};