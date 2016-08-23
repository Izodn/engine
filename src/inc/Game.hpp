#pragma once

#include "Window.hpp"
#include "GameLevel.hpp"

class Window;
class GameLevel;

class Game
{
	protected:
		GameLevel* m_CurrentLevel;
		bool m_Running;
		uint64_t m_CurrentFrame;

	public:
		Game();
		void Run();
		void AttachWindow(Window*);
		void ChangeToLevel(GameLevel*);
};