#include "inc/GameObject.hpp"

GameObject::GameObject()
{

}

void GameObject::Start()
{
	for (Component* component : m_Components.GetAll()) {
		component->Start();
	}
}

void GameObject::Update()
{
	for (Component* component : m_Components.GetAll()) {
		component->Update();
	}
}

void GameObject::SetName(std::string name)
{
	m_Name = name;
}

Collection<Component>* GameObject::Components()
{
	return &m_Components;
}

void GameObject::Cleanup()
{
	for (Component* component : m_Components.GetAll()) {
		if (component != NULL) {
			std::cout << "Deleting component: " << (void*)component << std::endl;
			free(component);
		}
	}
}