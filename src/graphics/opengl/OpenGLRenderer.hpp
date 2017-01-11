#pragma once

#include <iostream>
#include <string>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "../Renderer.hpp"
#include "../shader/opengl/OpenGLShader.hpp"
#include "../../core/Collection.hpp"

class OpenGLRenderer : public Renderer
{
	private:
		GLFWwindow* m_Window = NULL;
		Collection<OpenGLShader> m_Shaders;

	public:
		OpenGLRenderer();
		void SetWindow(GLFWwindow*);
		void Prepare();
		void Flush();
		void RegisterShader(Shader*);
		void Cleanup();
};