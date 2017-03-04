#include "MenuImage.hpp"

MenuImage::MenuImage(sf::Texture *texture, const sf::Vector2f &position, const sf::Vector2f &size) : ABasicElement(FLAG_EVENT::EVENT_NOTHING), _texture(texture)
{
	sf::Vector2u size_texture = texture->getSize();

	this->setPosition(sf::Vector2i(position.x, position.y));
	this->setSize(sf::Vector2i(size.x, size.y));

	this->_sprite.setTexture(*texture);
	this->_sprite.setPosition(position);

	this->_sprite.setScale(size.x / size_texture.x, size.y / size_texture.y);
}

MenuImage::~MenuImage()
{
	std::cout << "menu image delete" << std::endl;
}

void MenuImage::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->_sprite);
}