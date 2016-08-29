#include "inc/OpenGLApplication.hpp"

OpenGLApplication::OpenGLApplication()
{

}

void OpenGLApplication::Setup(EventHandler** handler, Renderer** renderer, Window** window)
{
	glfwInit();
	OpenGLWindow* newWindow = new OpenGLWindow(800, 600, "");
	Renderer* newRenderer = newWindow->GetRenderer();
	OpenGLEventHandler* newHandler = new OpenGLEventHandler();

	(*window) = newWindow;
	(*renderer) = newRenderer;
	(*handler) = newHandler;
}