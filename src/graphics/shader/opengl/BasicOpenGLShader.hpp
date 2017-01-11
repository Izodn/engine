#pragma once

#include "OpenGLShader.hpp"
#include "../../../core/Logger.hpp"

class BasicOpenGLShader : public OpenGLShader
{
	public:
		GLuint CompileShader();
};