#pragma once

#include <iostream>

#include "OpenGLShader.hpp"

class BasicOpenGLShader : public OpenGLShader
{
	public:
		GLuint CompileShader();
};