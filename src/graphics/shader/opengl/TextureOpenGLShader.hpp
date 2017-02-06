#pragma once

#include "OpenGLShader.hpp"
#include "../../../core/Logger.hpp"

class TextureOpenGLShader : public OpenGLShader
{
	public:
		GLuint CompileShader();
};