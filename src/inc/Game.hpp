#pragma once

#include <iostream>

#include "Window.hpp"
#include "GameLevel.hpp"
#include "Timer.hpp"

class Window;
class GameLevel;

class Game
{
	protected:
		GameLevel* m_CurrentLevel;
		bool m_Running;
		uint64_t m_CurrentFrame;
		uint64_t m_UpdateTickRate;
		uint64_t m_LastUpdateTick;
		Timer m_Timer;

	public:
		Game();
		void Run();
		void AttachWindow(Window*);
		void ChangeToLevel(GameLevel*);
		void Cleanup();
		void UpdateTickRate(uint64_t);
};