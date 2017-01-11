#pragma once

#include "RenderComponent.hpp"

#include "../graphics/shader/opengl/OpenGLShader.hpp"
#include "../graphics/opengl/OpenGLRenderer.hpp"

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

class FillSquare : public RenderComponent
{
	public:
		void Start() {};
		void Update() {};
		void RenderUpdate(Renderer*);
};