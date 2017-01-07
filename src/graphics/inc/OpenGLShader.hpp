#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "Shader.hpp"

class OpenGLShader : public Shader
{
	private:
		GLuint m_Id;
		bool m_Compiled = false;

	public:
		GLuint GetId();
		void Compile();

	protected:
		virtual GLuint CompileShader() = 0;
};