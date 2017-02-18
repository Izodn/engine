#pragma once

class GameObject;
class Transform;

class Component
{
	protected:
		GameObject* m_GameObject;
		Transform* m_Transform;

	public:
		void SetGameObject(GameObject*);
		virtual void Start() = 0;
		virtual void Update(double) = 0;
};