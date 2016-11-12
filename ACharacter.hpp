#pragma once
#include <SFML/Graphics.hpp>
#include "IObject.hpp"
#include "Tool.hpp"

class DataContainer;
class MapCase;

class ACharacter : public IObject
{
public:
	ACharacter();
	virtual ~ACharacter();
	virtual void	move(const sf::Vector2f & coord);
	sf::Vector2u getSizeTexture() const;
};