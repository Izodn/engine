#pragma once

#include <iostream>

#include "EventHandler.hpp"
#include "graphics/Renderer.hpp"
#include "graphics/Window.hpp"
#include "GameLevel.hpp"
#include "core/Timer.hpp"
#include "opengl/OpenGLApplication.hpp"

class EventHandler;
class Renderer;
class Window;
class GameLevel;
class Timer;
class OpenGLApplication;

class Game
{
	protected:
		EventHandler* m_EventHandler = nullptr;
		Renderer* m_Renderer = nullptr;
		Window* m_Window = nullptr;
		GameLevel* m_CurrentLevel = nullptr;
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

	public:
		template<typename T>
		void RegisterShader()
		{
			m_Renderer->RegisterShader<T>();
		};

};