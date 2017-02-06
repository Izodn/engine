#pragma once

#include "Component.hpp"
#include "../maths/Quaternion.hpp"

class Transform : public Component
{
	protected:
		Vector3 m_Position;
		Vector3 m_Scale;
		Quaternion m_Rotation;

	public:
		Transform();
		void Start();
		void Update(double);

		// Getters
		Vector3* GetPosition();
		Vector3* GetScale();
		Quaternion* GetRotation();

		// Setters
		Transform SetPosition(Vector3);
		Transform SetScale(Vector3);
		Transform SetRotation(Quaternion);
};