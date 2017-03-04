#pragma once
#include <SFML/Graphics.hpp>
#include "ABasicElement.hpp"
#include "DataContainer.hpp"

class MenuImage : public ABasicElement
{
public:
	MenuImage(sf::Texture *, const sf::Vector2f &, const sf::Vector2f &);
	virtual ~MenuImage();

public:
	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Texture		*_texture;
	sf::Sprite		_sprite;
};

