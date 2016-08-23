#include "inc/Game.hpp"

Game::Game() : m_Running(false), m_CurrentFrame(0)
{

}

void Game::Run()
{
	m_Running = true;
	while (m_Running) {
		m_CurrentFrame++;
		m_CurrentLevel->UpdateObjects();
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