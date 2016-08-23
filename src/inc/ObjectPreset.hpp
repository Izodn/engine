#pragma once

#include "GameObject.hpp"

class GameObject;

class ObjectPreset
{
	public:
		virtual GameObject* CreateNew() = 0;
};