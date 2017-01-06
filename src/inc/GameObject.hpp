#pragma once

#include <string>
#include <iostream>

#include "Collection.hpp"
#include "component/Component.hpp"
#include "GameLevel.hpp"

class Component;
class GameLevel;

class GameObject
{
	private:
		std::string m_Name;
		Collection<Component> m_Components;
		GameLevel* m_GameLevel;

	public:
		GameObject();
		void SetName(std::string);
		Collection<Component>* Components();
		void SetLevel(GameLevel*);
		GameLevel* GetLevel();
		void Start();
		void Update();
		void Cleanup();
};