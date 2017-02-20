#include "Game.hpp"

#include "profiler/Profiler.hpp"

Game::Game() :
	m_CurrentLevel(nullptr),
	m_Running(false),
	m_CurrentFrame(0),
	m_UpdateTickRate(120),
	m_LastUpdateTick(0),
	m_Timer(Timer::Instance())
{
	OpenGLApplication app;
	app.Setup(this, &m_EventHandler, &m_Renderer, &m_Window);
}

void Game::Run()
{
	m_Running = true;
	uint64_t lastFpsOut = 0;
	uint64_t lastFpsFrame = 0;

	while (m_Running) {
		Profiler::Instance()->Reset();
		Profiler::Instance()->Start("Game loop");
		{
			m_CurrentFrame++;

			// Poll events
			Profiler::Instance()->Start("Poll events");
			{
				m_EventHandler->PollEvents();
			}
			Profiler::Instance()->Stop("Poll events");

			// Update timer
			uint64_t tick = m_Timer->GetTick();
			uint64_t deltaTick = tick - m_LastUpdateTick;
			if (deltaTick >= (1000 / m_UpdateTickRate)) {
				Profiler::Instance()->Start("Update objects");
				{
					m_CurrentLevel->UpdateObjects((double)deltaTick / 1000.0f);
				}
				Profiler::Instance()->Stop("Update objects");

				m_LastUpdateTick = tick;

				// Sync input handling for correct pressed/released triggers
				Input::Sync();
				Input::ClearReleased();
			}

			// Prepare the window for drawing
			Profiler::Instance()->Start("Prepare renderer");
			{
				m_Renderer->Prepare();
			}
			Profiler::Instance()->Stop("Prepare renderer");

			// Render object
			Profiler::Instance()->Start("Render level objects");
			{
				m_CurrentLevel->RenderUpdateObjects();
			}
			Profiler::Instance()->Stop("Render level objects");

			// Flush the graphics to the window
			Profiler::Instance()->Start("Flush renderer");
			{
				m_Renderer->Flush();
			}
			Profiler::Instance()->Stop("Flush renderer");

			// Output FPS
			if ((tick - lastFpsOut) >= 1000) {
				double fps = (m_CurrentFrame - lastFpsFrame);
				fps /= (tick - lastFpsOut) / 1000;

				Logger() << "FPS: " << fps << "\n";
				lastFpsOut = tick;
				lastFpsFrame = m_CurrentFrame;
			}
		}
		Profiler::Instance()->Stop("Game loop");
		Profiler::Instance()->Output();
	}

	Logger() << "Initiating cleanup" << "\n";
	Cleanup();
}

void Game::Stop()
{
	Logger() << "Game::Stop() called" << "\n";
	m_Running = false;
}

void Game::ChangeToLevel(GameLevel* level)
{
	Logger() << "Changing to level: " << (void*)level << "\n";

	// If we're on a level currently, tell the old level to cleanup
	if (m_CurrentLevel != nullptr) {
		m_CurrentLevel->Cleanup();
	}

	if (level != nullptr) {
		// Set the new level
		m_CurrentLevel = level;
		m_CurrentLevel->SetGame(this);
		m_CurrentLevel->Init();
		m_CurrentLevel->StartObjects();
	}

	Logger() << "Change to level successful" << "\n";
}

void Game::Cleanup()
{
	if (m_CurrentLevel != nullptr) {
		// Trigger cleanup
		m_CurrentLevel->Cleanup();

		// Actually free the memory
		Logger() << "Deleting level: " << (void*)m_CurrentLevel << "\n";
		free(m_CurrentLevel);
		Logger() << "Level successfully deleted" << "\n";
	}
	m_Renderer->Cleanup();
}

void Game::UpdateTickRate(uint64_t tickRate)
{
	// Game tick rate in MS
	m_UpdateTickRate = tickRate;
	if (m_UpdateTickRate > 1000 || m_UpdateTickRate == 0) {
		m_UpdateTickRate = 1000;
	}
}

Window* Game::GetWindow()
{
	return m_Window;
}