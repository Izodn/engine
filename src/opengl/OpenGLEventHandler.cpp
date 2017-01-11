#include "OpenGLEventHandler.hpp"

OpenGLEventHandler* OpenGLEventHandler::Self()
{
	static OpenGLEventHandler* instance = new OpenGLEventHandler();
	return instance;
};

void OpenGLEventHandler::stMouseButtonCallback(GLFWwindow*, int button, int action, int)
{
	// Ignore repeat
	if (action == 2) {
		return;
	}

	Self()->MouseButtonCallback(button, action);
}

void OpenGLEventHandler::MouseButtonCallback(int button, int action)
{
	auto got = m_MouseButtonPairs.find(button);
	if (got != m_MouseButtonPairs.end()) {
		if (action == 1) {
			std::cout << "Click press: " << got->second << std::endl;
			Input::Press(got->second);
		} else if (action == 0) {
			std::cout << "Click release: " << got->second << std::endl;
			Input::Release(got->second);
		}
	} else {
		std::cout
			<< "Unregistered click:" << button
			<< " action:" << action << std::endl;
	}
}

void OpenGLEventHandler::stKeyCallback(GLFWwindow*, int button, int, int action, int)
{
	// Ignore repeat
	if (action == 2) {
		return;
	}

	Self()->KeyCallback(button, action);
}

void OpenGLEventHandler::KeyCallback(int button, int action)
{
	auto got = m_KeyPairs.find(button);
	if (got != m_KeyPairs.end()) {
		if (action == 1) {
			std::cout << "Key press: " << button << std::endl;
			Input::Press(got->second);
		} else if (action == 0) {
			std::cout << "Key Release: " << button << std::endl;
			Input::Release(got->second);
		}
	} else {
		std::cout
			<< "Unregistered button:" << button
			<< " action:" << action << std::endl;
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
	glfwSetKeyCallback(m_Window, &OpenGLEventHandler::stKeyCallback);
}

void OpenGLEventHandler::PollEvents()
{
	glfwPollEvents();
	if (glfwWindowShouldClose(m_Window)) {
		m_Game->Stop();
	}
}