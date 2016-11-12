#pragma once
#include <SFML/Graphics.hpp>
#include "IObject.hpp"

class Item : public IObject
{
public:
	Item();
	virtual ~Item();

	virtual void	move(const sf::Vector2f & coord);
};