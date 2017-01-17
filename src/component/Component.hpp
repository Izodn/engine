#pragma once

class GameObject;

class Component
{
	protected:
		GameObject* m_GameObject;

	public:
		void SetGameObject(GameObject*);
		virtual void Start() = 0;
		virtual void Update(double) = 0;
};