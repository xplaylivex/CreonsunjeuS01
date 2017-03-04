#include "Inputable.hpp"
#include <iostream>

Inputable::Inputable()
{
}

Inputable::~Inputable()
{
	std::cout << "inputable delete" << std::endl;
}

bool Inputable::isInputable() const
{
	return true;
}

bool Inputable::input(const sf::Event &event)
{
	return this->_callback(event);
}
