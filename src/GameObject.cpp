#include "GameObject.hpp"

#include "component/Component.hpp"
#include "component/RenderComponent.hpp"
#include "component/Transform.hpp"

GameObject::GameObject()
{
	m_Components.Add<Transform>();
	m_Transform = m_Components.Get<Transform>();
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

void GameObject::Update(double deltaTime)
{
	// Generic components
	for (Component* component : m_Components.GetAll()) {
		component->Update(deltaTime);
	}

	// Render components
	for (RenderComponent* component : m_RenderComponents.GetAll()) {
		component->Update(deltaTime);
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

Transform* GameObject::GetTransform()
{
	return m_Transform;
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