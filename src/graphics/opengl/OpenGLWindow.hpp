#pragma once

#include <iostream>
#include <string>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "../Window.hpp"
#include "../Renderer.hpp"
#include "OpenGLRenderer.hpp"

class Window;
class Renderer;
class OpenGLRenderer;

class OpenGLWindow : public Window
{
	private:
		GLFWwindow* m_Window = NULL;
		OpenGLRenderer* m_Renderer = NULL;
		int m_Width;
		int m_Height;
		std::string m_Title;

	public:
		OpenGLWindow(int, int, std::string);
		void SetRenderer(Renderer*);
		Renderer* GetRenderer();
		GLFWwindow* GetWindow();
		void SetResolution(int, int);
		void SetTitle(std::string);
};