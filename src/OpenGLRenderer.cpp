#include "inc/OpenGLRenderer.hpp"

#include "graphics/inc/BasicOpenGLShader.hpp"

OpenGLRenderer::OpenGLRenderer()
{

}

void OpenGLRenderer::SetWindow(GLFWwindow* window)
{
	m_Window = window;
}

void OpenGLRenderer::Flush()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Write buffer data to the screen
	glfwSwapBuffers(m_Window);
}

void OpenGLRenderer::RegisterShader(Shader* shader)
{
	// Cast to OpenGLShader. Potentially dangerous
	OpenGLShader* glShader = (OpenGLShader*)shader;

	std::cout << "Compiling shader: " << (void*)glShader << std::endl;

	// Compile the shader.
	glShader->Compile();

	std::cout << "Finished shader compile" << std::endl;
}

void OpenGLRenderer::Cleanup()
{
	std::cout << "OpenGLRenderer::Cleanup()" << std::endl;
	glfwTerminate();
}