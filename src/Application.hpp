#pragma once

#include "Game.hpp"
#include "EventHandler.hpp"
#include "graphics/Renderer.hpp"
#include "graphics/Window.hpp"

class Game;

class Application
{
	public:
		virtual void Setup(Game*, EventHandler**, Renderer**, Window**) = 0;
};