#include "inc/OpenGLRenderer.hpp"

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

void OpenGLRenderer::Cleanup()
{
	std::cout << "OpenGLRenderer::Cleanup()" << std::endl;
	glfwTerminate();
}