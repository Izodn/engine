#pragma once

#include "Game.hpp"
#include "EventHandler.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

class Game;

class Application
{
	public:
		virtual void Setup(Game*, EventHandler**, Renderer**, Window**) = 0;
};