#include "inc/component/Component.hpp"

Component::Component()
{

}

InputHandler* Component::Input()
{
	return m_InputHandler;
}