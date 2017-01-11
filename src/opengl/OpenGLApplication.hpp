#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "../Application.hpp"
#include "../EventHandler.hpp"
#include "../graphics/Renderer.hpp"
#include "../graphics/Window.hpp"
#include "../graphics/opengl/OpenGLWindow.hpp"
#include "OpenGLEventHandler.hpp"
#include "../Game.hpp"

class Application;
class EventHandler;
class Renderer;
class Window;
class OpenGLWindow;
class OpenGLEventHandler;
class Game;

class OpenGLApplication : public Application
{
	public:
		void Setup(Game*, EventHandler**, Renderer**, Window**);
};