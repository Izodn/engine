#pragma once

#include <iostream>

#include "EventHandler.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include "GameLevel.hpp"
#include "Timer.hpp"
#include "OpenGLApplication.hpp"

class EventHandler;
class Renderer;
class Window;
class GameLevel;
class Timer;
class OpenGLApplication;

class Game
{
	protected:
		EventHandler* m_EventHandler = NULL;
		Renderer* m_Renderer = NULL;
		Window* m_Window = NULL;
		GameLevel* m_CurrentLevel = NULL;
		bool m_Running;
		uint64_t m_CurrentFrame;
		uint64_t m_UpdateTickRate;
		uint64_t m_LastUpdateTick;
		Timer m_Timer;

	public:
		Game();
		void Run();
		void Stop();
		void ChangeToLevel(GameLevel*);
		void Cleanup();
		void UpdateTickRate(uint64_t);
		Window* GetWindow();
};