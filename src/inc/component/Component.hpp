#pragma once

#include "../Input.hpp"
#include "../GameObject.hpp"

class Input;
class GameObject;

class Component
{
	protected:
		GameObject* m_GameObject;

	public:
		Component();
		void SetGameObject(GameObject*);
		virtual void Start() = 0;
		virtual void Update() = 0;
};