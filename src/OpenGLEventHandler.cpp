#include "inc/OpenGLEventHandler.hpp"

OpenGLEventHandler::OpenGLEventHandler()
{

}

OpenGLEventHandler& OpenGLEventHandler::GetInstance()
{
	static OpenGLEventHandler instance;
	return instance;
};

void OpenGLEventHandler::stMouseButtonCallback(GLFWwindow*, int button, int action, int)
{
	GetInstance().MouseButtonCallback(button, action);
}

void OpenGLEventHandler::MouseButtonCallback(int button, int action)
{
	// Mouse one
	if (button == 0 && action == 1) {
		Input::Press(Input::Key::MOUSE_ONE);
	} else if (button == 0 && action == 0) {
		Input::Release(Input::Key::MOUSE_ONE);
	}

	// Mouse two
	else if (button == 1 && action == 1) {
		Input::Press(Input::Key::MOUSE_TWO);
	} else if (button == 1 && action == 0) {
		Input::Release(Input::Key::MOUSE_TWO);
	}
}

void OpenGLEventHandler::SetWindow(GLFWwindow* window)
{
	m_Window = window;
}

void OpenGLEventHandler::SetGame(Game* game)
{
	m_Game = game;
}

void OpenGLEventHandler::Register()
{
	// Set GLFW callbacks
	glfwSetMouseButtonCallback(m_Window, &OpenGLEventHandler::stMouseButtonCallback);
}

void OpenGLEventHandler::PollEvents()
{
	glfwPollEvents();
	if (glfwWindowShouldClose(m_Window)) {
		m_Game->Stop();
	}
}