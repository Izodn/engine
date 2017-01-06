#include "inc/component/Component.hpp"

Component::Component()
{

}

void Component::SetGameObject(GameObject* gameObject)
{
	m_GameObject = gameObject;
}