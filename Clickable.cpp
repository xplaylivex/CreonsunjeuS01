#include "Clickable.hpp"
#include <iostream>

Clickable::Clickable()
{
}

Clickable::Clickable(const sf::Vector2i &position, const sf::Vector2i &size) : _hitbox(position.x, position.y, size.x, size.y)
{
}

Clickable::~Clickable()
{
	std::cout << "clickable delete" << std::endl;
}

bool Clickable::isClickable() const
{
	return true;
}

bool Clickable::isClicked(const sf::Vector2f &position) const
{
	return this->_hitbox.contains(position);
}

void Clickable::setHitbox(const sf::Vector2f & position, const sf::Vector2f & size)
{
	this->_hitbox.left		= position.x;
	this->_hitbox.top		= position.y;
	this->_hitbox.width		= size.x;
	this->_hitbox.height	= size.y;
}

bool Clickable::click(const sf::Event &event)
{
	sf::Vector2f click_position(event.mouseButton.x, event.mouseButton.y);
	
	if (this->isClicked(click_position)) {
		return this->_callback(event);
	}

	return false;
}