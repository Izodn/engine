#include "inc/Game.hpp"

Game::Game() :
	m_CurrentLevel(NULL),
	m_Running(false),
	m_CurrentFrame(0),
	m_UpdateTickRate(120),
	m_LastUpdateTick(0)
{

}

void Game::Run()
{
	m_Running = true;
	while (m_Running) {
		m_CurrentFrame++;

		// Update timer
		uint64_t tick = m_Timer.GetTick();
		uint64_t deltaTick = tick - m_LastUpdateTick;
		if (deltaTick >= (1000 / m_UpdateTickRate)) {
			m_CurrentLevel->UpdateObjects();
			m_LastUpdateTick = tick;
		}
	}
}

void Game::AttachWindow(Window* window)
{

}

void Game::ChangeToLevel(GameLevel* level)
{
	// If we're on a level currently, tell the old level to cleanup
	if (m_CurrentLevel != NULL) {
		m_CurrentLevel->Cleanup();
	}

	if (level != NULL) {
		// Set the new level
		m_CurrentLevel = level;
		m_CurrentLevel->SetGame(this);
		m_CurrentLevel->Init();
	}
}

void Game::Cleanup()
{
	if (m_CurrentLevel != NULL) {
		// Trigger cleanup
		m_CurrentLevel->Cleanup();

		// Actually free the memory
		std::cout << "Deleting level: " << (void*)m_CurrentLevel << std::endl;
		free(m_CurrentLevel);
	}
}

void Game::UpdateTickRate(uint64_t tickRate)
{
	// Game tick rate in MS
	m_UpdateTickRate = tickRate;
	if (m_UpdateTickRate > 1000 || m_UpdateTickRate == 0) {
		m_UpdateTickRate = 1000;
	}
}