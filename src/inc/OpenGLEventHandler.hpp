#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "EventHandler.hpp"

class EventHandler;

class OpenGLEventHandler : public EventHandler
{
	public:
		OpenGLEventHandler();
		void PollEvents();
};