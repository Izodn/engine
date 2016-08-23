#pragma once

#include <string>

#include "Collection.hpp"
#include "component/Component.hpp"

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
};