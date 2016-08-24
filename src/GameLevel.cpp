#include "inc/GameLevel.hpp"

GameLevel::GameLevel()
{

}

void GameLevel::SetGame(Game* game)
{
	m_Game = game;
}

void GameLevel::UpdateObjects()
{
	for (GameObject* object : m_GameObjects) {
		if (object != NULL) {
			object->Update();
		} else {
			std::cout << "Tried to update NULL GameObject" << std::endl;
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
			std::cout << "Deleting object: " << (void*)object << std::endl;
			free(object);
		} else {
			std::cout << "Tried to remove NULL GameObject" << std::endl;
		}
	}
}