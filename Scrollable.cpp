#include "Scrollable.hpp"

Scrollable::Scrollable()
{
}


Scrollable::~Scrollable()
{
}

bool Scrollable::isScrollable() const
{
	return true;
}

bool Scrollable::scroll(const sf::Event &event)
{
	return this->_callback(event);
}
