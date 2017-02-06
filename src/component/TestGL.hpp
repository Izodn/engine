#pragma once

#include "RenderComponent.hpp"

#include "../graphics/shader/opengl/OpenGLShader.hpp"
#include "../graphics/opengl/OpenGLRenderer.hpp"

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TestGL : public RenderComponent
{
	private:
		GLuint m_VBO, m_VAO, m_EBO;
		GLuint m_Texture1, m_Texture2;

	public:
		void Start() {};
		void Update(double) {};
		void RenderStart(Renderer*);
		void RenderUpdate(Renderer*);
};