#include "Item.hpp"
#include "MapCase.hpp"

Item::Item() : IObject("assets/barrel_E.png")
{
	sf::Vector2u size_texture = this->_texture_character.getSize();
	if ((size_texture.x) / (float)(SIZE_TILE_X) > 1.0f || (size_texture.y) / (float)(SIZE_TILE_Y) > 1.0f) {
		this->_currentScale.x = std::min((float)(SIZE_TILE_X) / (size_texture.x), (float)(SIZE_TILE_Y) / (size_texture.y));
		this->_currentScale.y = this->_currentScale.x;
	}

	this->_character_sprite.setPosition(sf::Vector2f(-(size_texture.x * this->_currentScale.x / 2), -(size_texture.y * this->_currentScale.y) + (size_texture.y * 0.1 * this->_currentScale.y)));
	this->_character_sprite.setTexture(this->_texture_character);
	this->_character_sprite.setScale(this->_currentScale);

	/*TMP*/

	MapCase *random_case = DataContainer::getInstance()->map->getRandomCase();
	float x_float = (float)(rand() % 100) / 100;
	float y_float = (float)(rand() % 100) / 100;

	this->_position = sf::Vector2f(random_case->humanCoord.x + x_float, random_case->humanCoord.y + y_float);

	this->move(this->_position);
	this->_currentCase = random_case;
	if (random_case) {
		random_case->addObject(this);
	}
}


Item::~Item()
{
}


void Item::move(const sf::Vector2f &coord)
{
	sf::Vector2u size_texture = this->_texture_character.getSize();

	sf::Vector2f tmp = Tool::toWindowCoord(coord.x, coord.y);
	sf::Vector2f default_position = sf::Vector2f((size_texture.x * this->_currentScale.x / 2), (size_texture.y * this->_currentScale.y) - (size_texture.y * 0.1 * this->_currentScale.y));

	this->_character_sprite.setPosition(tmp - default_position);
	this->_position.x = coord.x;
	this->_position.y = coord.y;
}
