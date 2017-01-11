#pragma once

#include <iostream>

#include "Transform.hpp"
#include "../graphics/Renderer.hpp"

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
};