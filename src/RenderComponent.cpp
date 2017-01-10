#include "inc/component/RenderComponent.hpp"

#include "inc/GameObject.hpp"

void RenderComponent::Render()
{
	// If the game object hasn't somehow detached & we have a renderer
	if (m_GameObject != nullptr && m_Renderer != nullptr) {

		// We must have a transform component to render anything on screen
		if (m_GameObject->Components()->Has<Transform>()) {
			RenderUpdate(m_Renderer);
		} else {
			std::cout << "Cannot render without Transform component" << std::endl;
		}
	} else if (m_GameObject == nullptr) {
		std::cout << "m_GameObject == nullptr" << std::endl;
	} else if (m_Renderer == nullptr) {
		std::cout << "m_Renderer == nullptr" << std::endl;
	}
}

void RenderComponent::SetRenderer(Renderer* renderer)
{
	if (renderer != nullptr) {
		m_Renderer = renderer;
	} else {
		std::cout << "Tried to set null renderer" << std::endl;
	}
}

void RenderComponent::SetShader(Shader* shader)
{
	if (shader != nullptr) {
		m_Shader = shader;
	} else {
		std::cout << "Tried to set null shader" << std::endl;
	}
}