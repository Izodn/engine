#pragma once

#include <vector>
#include <iostream>

#include "Game.hpp"
#include "GameObject.hpp"

class Game;
class GameObject;

class GameLevel
{
	protected:
		std::vector<GameObject*> m_GameObjects;
		Game* m_Game;

	public:
		GameLevel();
		void StartObjects();
		void UpdateObjects();
		void Cleanup();
		void SetGame(Game*);

	public:
		virtual void Init() = 0;
};