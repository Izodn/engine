#pragma once

#include <string>
#include <iostream>

#include "Collection.hpp"
#include "component/Component.hpp"

class Component;

class GameObject
{
	private:
		std::string m_Name;
		Collection<Component> m_Components;

	public:
		GameObject();
		void SetName(std::string);
		Collection<Component>* Components();
		void Start();
		void Update();
		void Cleanup();
};