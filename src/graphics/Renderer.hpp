#pragma once

#include "../core/Collection.hpp"
#include "shader/Shader.hpp"

class Renderer
{
	protected:
		Collection<Shader> m_Shaders;

	public:
		Collection<Shader>* Shaders();
		virtual void Prepare() = 0;
		virtual void Flush() = 0;
		virtual void Cleanup() = 0;
		virtual void RegisterShader(Shader*) = 0;

	public:
		template<typename T>
		void RegisterShader()
		{
			m_Shaders.Add<T>();
			RegisterShader(m_Shaders.Get<T>());
		};
};