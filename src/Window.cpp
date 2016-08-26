#include "inc/Window.hpp"

Window::Window(uint64_t width, uint64_t height, std::string title)
{
	ChangeRenderer(Renderer::Type::OPENGL);
}

void Window::ChangeRenderer(Renderer::Type rendererType)
{
	Renderer* newRenderer = NULL;

	switch (rendererType) {
		case Renderer::OPENGL:
			newRenderer = new OpenGLRenderer();
			break;

		case Renderer::VULKAN:
			//newRenderer = new VulkanRenderer();
			break;
	}

	// Change out renderers
	if (newRenderer != NULL) {
		if (m_Renderer != NULL) {
			m_Renderer->Cleanup();
			free(m_Renderer);
		}
		m_Renderer = newRenderer;
	}
}