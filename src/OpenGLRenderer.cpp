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
	glfwSwapBuffers(m_Window);
}

void OpenGLRenderer::Cleanup()
{
	std::cout << "Cleanup()" << std::endl;
	glfwTerminate();
}