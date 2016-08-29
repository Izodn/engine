#pragma once

#include <string>

#include "Renderer.hpp"

class Renderer;

class Window
{
	public:
		virtual void SetRenderer(Renderer*) = 0;
		virtual Renderer* GetRenderer() = 0;
		virtual void SetResolution(int, int) = 0;
		virtual void SetTitle(std::string) = 0;
};