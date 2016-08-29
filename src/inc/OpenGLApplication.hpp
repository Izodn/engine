#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "EventHandler.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include "OpenGLWindow.hpp"
#include "OpenGLEventHandler.hpp"

class Application;
class EventHandler;
class Renderer;
class Window;
class OpenGLWindow;
class OpenGLEventHandler;

class OpenGLApplication : public Application
{
	public:
		OpenGLApplication();
		void Setup(EventHandler**, Renderer**, Window**);
};