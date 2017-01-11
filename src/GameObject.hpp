#pragma once

#include <string>

#include "core/Collection.hpp"
#include "core/Logger.hpp"
#include "GameLevel.hpp"

class Component;
class RenderComponent;
class GameLevel;

class GameObject
{
	private:
		std::string m_Name;
		Collection<Component> m_Components;
		Collection<RenderComponent> m_RenderComponents;
		GameLevel* m_GameLevel;

	public:
		void SetName(std::string);
		Collection<Component>* Components();
		Collection<RenderComponent>* RenderComponents();
		void SetLevel(GameLevel*);
		GameLevel* GetLevel();
		void Start();
		void Update();
		void RenderUpdate();
		void Cleanup();
};