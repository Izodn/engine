#pragma once

#include "Component.hpp"
#include "../maths/Vector3.hpp"

class Transform : public Component
{
	protected:
		Vector3 m_Position;
		Vector3 m_Scale;

	public:
		Transform() :
			m_Position(Vector3(0.0f, 0.0f, 0.0f)),
			m_Scale(Vector3(1.0f, 1.0f, 1.0f)) {};
		void Start() {};
		void Update(double) {};
		Vector3* GetPosition()
		{
			return &m_Position;
		};
		Vector3* GetScale()
		{
			return &m_Scale;
		};
};