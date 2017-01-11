#include "GameObject.hpp"

#include "component/Component.hpp"
#include "component/RenderComponent.hpp"

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
	// Generic components
	for (Component* component : m_Components.GetAll()) {
		component->SetGameObject(this);
		component->Start();
	}

	// Render components
	for (RenderComponent* component : m_RenderComponents.GetAll()) {
		component->SetGameObject(this);
		component->SetRenderer(
			m_GameLevel->GetGame()->GetWindow()->GetRenderer()
		);
		component->Start();
	}
}

void GameObject::Update()
{
	// Generic components
	for (Component* component : m_Components.GetAll()) {
		component->Update();
	}

	// Render components
	for (RenderComponent* component : m_RenderComponents.GetAll()) {
		component->Update();
	}
}

void GameObject::RenderUpdate()
{
	for (RenderComponent* component : m_RenderComponents.GetAll()) {
		component->Render();
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

Collection<RenderComponent>* GameObject::RenderComponents()
{
	return &m_RenderComponents;
}

void GameObject::Cleanup()
{
	// Generic components
	for (Component* component : m_Components.GetAll()) {
		if (component != NULL) {
			Logger() << "Deleting component: " << (void*)component << "\n";
			free(component);
			Logger() << "Deleted component" << "\n";
		}
	}

	// Render components
	for (RenderComponent* component : m_RenderComponents.GetAll()) {
		if (component != NULL) {
			Logger() << "Deleting render component: " << (void*)component << "\n";
			free(component);
			Logger() << "Deleted component" << "\n";
		}
	}
}