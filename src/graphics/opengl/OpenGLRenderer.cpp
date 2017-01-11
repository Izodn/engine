#include "OpenGLRenderer.hpp"

OpenGLRenderer::OpenGLRenderer()
{

}

void OpenGLRenderer::SetWindow(GLFWwindow* window)
{
	m_Window = window;
}

void OpenGLRenderer::Prepare()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderer::Flush()
{
	// Write buffer data to the screen
	glfwSwapBuffers(m_Window);
}

void OpenGLRenderer::RegisterShader(Shader* shader)
{
	// Cast to OpenGLShader. Potentially dangerous
	OpenGLShader* glShader = (OpenGLShader*)shader;

	Logger() << "Compiling shader: " << (void*)glShader << "\n";

	// Compile the shader.
	glShader->Init();

	Logger() << "Finished shader compile" << "\n";
}

void OpenGLRenderer::Cleanup()
{
	Logger() << "OpenGLRenderer::Cleanup()" << "\n";
	glfwTerminate();
}