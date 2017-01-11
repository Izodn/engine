#include "Component.hpp"

#include "../GameObject.hpp"

void Component::SetGameObject(GameObject* gameObject)
{
	m_GameObject = gameObject;
}