#include "OpenGLShader.hpp"

GLuint OpenGLShader::GetId()
{
	if (!m_Compiled) {
		Init();
	}
	return m_Id;
}

void OpenGLShader::Init()
{
	m_Id = CompileShader();
	m_Compiled = true;
}