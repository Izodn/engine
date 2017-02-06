#include "RenderComponent.hpp"

#include "../GameObject.hpp"

void RenderComponent::Render()
{
	// If the game object hasn't somehow detached & we have a renderer
	if (m_GameObject != nullptr && m_Renderer != nullptr) {

		// We must have a transform component to render anything on screen
		if (m_GameObject->Components()->Has<Transform>()) {
			RenderUpdate(m_Renderer);
		} else {
			Logger() << "Cannot render without Transform component" << "\n";
		}
	} else if (m_GameObject == nullptr) {
		Logger() << "m_GameObject == nullptr" << "\n";
	} else if (m_Renderer == nullptr) {
		Logger() << "m_Renderer == nullptr" << "\n";
	}
}

void RenderComponent::SetRenderer(Renderer* renderer)
{
	if (renderer != nullptr) {
		m_Renderer = renderer;
		RenderStart(m_Renderer);
	} else {
		Logger() << "Tried to set null renderer" << "\n";
	}
}

void RenderComponent::SetShader(Shader* shader)
{
	if (shader != nullptr) {
		m_Shader = shader;
	} else {
		Logger() << "Tried to set null shader" << "\n";
	}
}