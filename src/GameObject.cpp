#include "inc/GameObject.hpp"

GameObject::GameObject()
{

}

void GameObject::SetLevel(GameLevel* gameLevel)
{
	m_GameLevel = gameLevel;
}

GameLevel* GameObject::GetLevel()
{
	return m_GameLevel;
}

void GameObject::Start()
{
	for (Component* component : m_Components.GetAll()) {
		component->SetGameObject(this);
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