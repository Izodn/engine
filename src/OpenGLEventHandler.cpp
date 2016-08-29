#include "inc/OpenGLEventHandler.hpp"

OpenGLEventHandler::OpenGLEventHandler()
{

}

void OpenGLEventHandler::PollEvents()
{
	glfwPollEvents();
}