#include "CharacterSprite.hpp"

CharacterSprite::CharacterSprite() : ACharacter()
{
}

CharacterSprite::~CharacterSprite()
{
}

void CharacterSprite::changeOrientation(const std::list<KeyConstants> &action_list)
{
	sf::Vector2u size_texture = this->_texture_character.getSize();
	sf::Vector2i size_sprite(size_texture.x / 3, size_texture.y / 3);
	char orientation = 0;

	for (std::list<KeyConstants>::const_iterator it = action_list.begin(); it != action_list.end(); ++it) {
		if (*it == KeyConstants::FORWARD) {
			orientation |= 1;
		}
		else if (*it == KeyConstants::BACKWARD) {
			orientation |= 2;
		}
		else if (*it == KeyConstants::LEFT) {
			orientation |= 4;
		}
		else if (*it == KeyConstants::RIGHT) {
			orientation |= 8;
		}
	}

	switch (orientation) {
		case 1:
			this->_character_sprite.setTextureRect(sf::IntRect(size_sprite.x, 0, size_sprite.x, size_sprite.y));
			break;
		case 2:
			this->_character_sprite.setTextureRect(sf::IntRect(size_sprite.x, 2 * size_sprite.y, size_sprite.x, size_sprite.y));
			break;
		case 4:
			this->_character_sprite.setTextureRect(sf::IntRect(0, size_sprite.y, size_sprite.x, size_sprite.y));
			break;
		case 5:
			this->_character_sprite.setTextureRect(sf::IntRect(0, 0, size_sprite.x, size_sprite.y));
			break;
		case 6:
			this->_character_sprite.setTextureRect(sf::IntRect(0, 2 * size_sprite.y, size_sprite.x, size_sprite.y));
			break;
		case 8:
			this->_character_sprite.setTextureRect(sf::IntRect(2 * size_sprite.x, size_sprite.y, size_sprite.x, size_sprite.y));
			break;
		case 9:
			this->_character_sprite.setTextureRect(sf::IntRect(2 * size_sprite.x, 0, size_sprite.x, size_sprite.y));
			break;
		case 10:
			this->_character_sprite.setTextureRect(sf::IntRect(2 * size_sprite.x, 2 * size_sprite.y, size_sprite.x, size_sprite.y));
			break;
	}
}
