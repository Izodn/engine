#include "Transform.hpp"

Transform::Transform() :
	m_Position(Vector3()),
	m_Scale(Vector3() + 1.0f),
	m_Rotation(Vector3::Forward())
{

}

void Transform::Start()
{

}

void Transform::Update(double deltaTime)
{

}

// Getters
Vector3* Transform::GetPosition()
{
	return &m_Position;
}
Vector3* Transform::GetScale()
{
	return &m_Scale;
}
Quaternion* Transform::GetRotation()
{
	return &m_Rotation;
}

// Setters
Transform Transform::SetPosition(Vector3 position)
{
	m_Position = position;
	return *this;
}
Transform Transform::SetScale(Vector3 scale)
{
	m_Scale = scale;
	return *this;
}
Transform Transform::SetRotation(Quaternion rotation)
{
	m_Rotation = rotation;
	return *this;
}