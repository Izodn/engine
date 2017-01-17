#pragma once

#include <string>

#include "core/Collection.hpp"
#include "core/Logger.hpp"
#include "GameLevel.hpp"

class Component;
class RenderComponent;
class GameLevel;
class Transform;

class GameObject
{
	private:
		std::string m_Name;
		Collection<Component> m_Components;
		Collection<RenderComponent> m_RenderComponents;
		Transform* m_Transform;
		GameLevel* m_GameLevel;

	public:
		GameObject();
		void SetName(std::string);
		Collection<Component>* Components();
		Collection<RenderComponent>* RenderComponents();
		Transform* GetTransform();
		void SetLevel(GameLevel*);
		GameLevel* GetLevel();
		void Start();
		void Update(double);
		void RenderUpdate();
		void Cleanup();
};