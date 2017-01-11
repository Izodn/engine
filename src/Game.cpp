#include "Game.hpp"

Game::Game() :
	m_CurrentLevel(nullptr),
	m_Running(false),
	m_CurrentFrame(0),
	m_UpdateTickRate(120),
	m_LastUpdateTick(0)
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
		m_CurrentFrame++;

		// Poll events
		m_EventHandler->PollEvents();

		// Update timer
		uint64_t tick = m_Timer.GetTick();
		uint64_t deltaTick = tick - m_LastUpdateTick;
		if (deltaTick >= (1000 / m_UpdateTickRate)) {
			m_CurrentLevel->UpdateObjects();
			m_LastUpdateTick = tick;

			// Clear all inputs
			Input::Clear();
		}

		// Prepare the window for drawing
		m_Renderer->Prepare();

		// Render object
		m_CurrentLevel->RenderUpdateObjects();

		// Flush the graphics to the window
		m_Renderer->Flush();

		// Output FPS
		if ((tick - lastFpsOut) >= 1000) {
			double fps = (m_CurrentFrame - lastFpsFrame);
			fps /= (tick - lastFpsOut) / 1000;

			Logger() << "FPS: " << fps << "\n";
			lastFpsOut = tick;
			lastFpsFrame = m_CurrentFrame;
		}
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