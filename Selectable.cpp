#include "Selectable.hpp"



Selectable::Selectable()
{
}


Selectable::~Selectable()
{
}

bool Selectable::isSelectable() const
{
	return true;
}

bool Selectable::select(const sf::Event &event)
{
	return this->_callback(event);
}
