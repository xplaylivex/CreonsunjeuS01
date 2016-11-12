#include "ACharacter.hpp"

ACharacter::ACharacter() : IObject("assets/orientation.png")
{
	sf::Vector2u size_texture = this->_texture_character.getSize();
	if ((size_texture.x / 3) / (float)(SIZE_TILE_X) > 1.0f || (size_texture.y / 3) / (float)(SIZE_TILE_Y) > 1.0f) {
		this->_currentScale.x = std::min((float)(SIZE_TILE_X) / (size_texture.x / 3), (float)(SIZE_TILE_Y) / (size_texture.y / 3));
		this->_currentScale.y = this->_currentScale.x;
	}

	this->_character_sprite.setPosition(sf::Vector2f(-(size_texture.x / 3 * this->_currentScale.x / 2), -(size_texture.y / 3 * this->_currentScale.y) + (size_texture.y / 3 * 0.1 * this->_currentScale.y)));
	this->_character_sprite.setTexture(this->_texture_character);
	this->_character_sprite.setTextureRect(sf::IntRect(size_texture.x / 3 * 2, size_texture.y / 3 * 2, size_texture.x / 3, size_texture.y / 3));
	this->_character_sprite.setScale(this->_currentScale);
}

ACharacter::~ACharacter()
{
}

void ACharacter::move(const sf::Vector2f &coord)
{
	sf::Vector2u size_texture = this->_texture_character.getSize();
	sf::Vector2f tmp = Tool::toWindowCoord(coord.x, coord.y);
	sf::Vector2f default_position = sf::Vector2f((size_texture.x / 3 * this->_currentScale.x / 2), (size_texture.y / 3 * this->_currentScale.y) - (size_texture.y / 3 * 0.1 * this->_currentScale.y));

	this->_character_sprite.setPosition(tmp - default_position);
	this->_position.x = coord.x;
	this->_position.y = coord.y;
}

sf::Vector2u ACharacter::getSizeTexture() const
{
	sf::Vector2u size = this->_texture_character.getSize();
	size.x /= 3;
	size.y /= 3;
	return size;
}