#pragma once

#include <vector>

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
		void StartObjects();
		void UpdateObjects(double);
		void RenderUpdateObjects();
		void Cleanup();
		void SetGame(Game*);
		Game* GetGame();

	public:
		virtual void Init() = 0;
};