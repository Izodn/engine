#pragma once

#include "Transform.hpp"
#include "../graphics/Renderer.hpp"
#include "../core/Logger.hpp"

class RenderComponent : virtual public Component
{
	private:
		Renderer* m_Renderer;

	protected:
		Shader* m_Shader;

	public:
		void Render();
		void SetRenderer(Renderer*);
		Shader* GetShader();
		void SetShader(Shader*);

	protected:
		virtual void RenderUpdate(Renderer*) = 0;

	public:
		virtual void RenderStart(Renderer*) = 0;
};