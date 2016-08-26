#pragma once

#include <iostream>
#include <string>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "Renderer.hpp"

class OpenGLRenderer : public Renderer
{
	public:
		OpenGLRenderer();
		void Cleanup();
};