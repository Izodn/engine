#include "inc/component/Component.hpp"

#include "inc/GameObject.hpp"

void Component::SetGameObject(GameObject* gameObject)
{
	m_GameObject = gameObject;
}