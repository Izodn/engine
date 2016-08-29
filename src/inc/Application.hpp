#pragma once

#include "EventHandler.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

class Application
{
	public:
		virtual void Setup(EventHandler**, Renderer**, Window**) = 0;
};