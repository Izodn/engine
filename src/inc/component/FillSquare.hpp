#pragma once

#include "RenderComponent.hpp"

#include "../../graphics/inc/OpenGLShader.hpp"
#include "../OpenGLRenderer.hpp"

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