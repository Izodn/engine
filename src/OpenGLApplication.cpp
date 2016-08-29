#include "inc/OpenGLApplication.hpp"

OpenGLApplication::OpenGLApplication()
{

}

void OpenGLApplication::Setup(EventHandler** handler, Renderer** renderer, Window** window)
{
	std::cout << "Got here" << std::endl;
	glfwInit();
	OpenGLWindow* newWindow = new OpenGLWindow(800, 600, "Engine Test");
	Renderer* newRenderer = newWindow->GetRenderer();
	OpenGLEventHandler* newHandler = new OpenGLEventHandler();

	(*window) = newWindow;
	(*renderer) = newRenderer;
	(*handler) = newHandler;
}