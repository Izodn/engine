#include "inc/OpenGLShader.hpp"

#include <iostream>

GLuint OpenGLShader::GetId()
{
	if (!m_Compiled) {
		Compile();
	}
	return m_Id;
}

void OpenGLShader::Compile()
{
	m_Id = CompileShader();
	m_Compiled = true;
}