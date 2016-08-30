#pragma once

#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "Input.hpp"
#include "EventHandler.hpp"
#include "Game.hpp"

class EventHandler;
class Game;
class Input;

class OpenGLEventHandler : public EventHandler
{
	private:
		GLFWwindow* m_Window = NULL;
		Game* m_Game = NULL;

	public:
		static OpenGLEventHandler& GetInstance();
		static void stMouseButtonCallback(GLFWwindow*, int, int, int);

	public:
		OpenGLEventHandler();
		void MouseButtonCallback(int, int);
		void SetWindow(GLFWwindow*);
		void SetGame(Game*);
		void Register();
		void PollEvents();
};