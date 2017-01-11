#include "OpenGLApplication.hpp"

void OpenGLApplication::Setup(Game* game, EventHandler** handler, Renderer** renderer, Window** window)
{
	// Initialize GLFW
	glfwInit();

	// Create window
	OpenGLWindow* newWindow = new OpenGLWindow(800, 600, "");

	// Create renderer
	Renderer* newRenderer = newWindow->GetRenderer();

	// Create & initialize event/input handlers
	OpenGLEventHandler* newHandler = new OpenGLEventHandler();
	newHandler->SetGame(game);
	newHandler->SetWindow(newWindow->GetWindow());
	newHandler->Register();

	// Set the new data
	(*window) = newWindow;
	(*renderer) = newRenderer;
	(*handler) = newHandler;
}