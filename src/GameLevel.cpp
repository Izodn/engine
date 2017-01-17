#include "GameLevel.hpp"

void GameLevel::SetGame(Game* game)
{
	m_Game = game;
}

Game* GameLevel::GetGame()
{
	return m_Game;
}

void GameLevel::StartObjects()
{
	Logger() << "GameLevel::StartObjects" << "\n";
	for (GameObject* object : m_GameObjects) {
		if (object != NULL) {
			object->SetLevel(this);
			object->Start();
		} else {
			Logger() << "Tried to start NULL GameObject" << "\n";
		}
	}
}

void GameLevel::UpdateObjects(double deltaTime)
{
	for (GameObject* object : m_GameObjects) {
		if (object != NULL) {
			object->Update(deltaTime);
		} else {
			Logger() << "Tried to update NULL GameObject" << "\n";
		}
	}
}

void GameLevel::RenderUpdateObjects()
{
	for (GameObject* object : m_GameObjects) {
		if (object != NULL) {
			object->RenderUpdate();
		} else {
			Logger() << "Tried to render update NULL GameObject" << "\n";
		}
	}
}

void GameLevel::Cleanup()
{
	for (GameObject* object : m_GameObjects) {
		if (object != NULL) {
			// Trigger object cleanup
			object->Cleanup();

			// Actually free memory
			Logger() << "Deleting object: " << (void*)object << "\n";
			free(object);
			Logger() << "Object successfully deleted" << "\n";
		} else {
			Logger() << "Tried to remove NULL GameObject" << "\n";
		}
	}
}