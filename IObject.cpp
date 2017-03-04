#include "IObject.hpp"
#include "DataContainer.hpp"

IObject::IObject(const std::string &filename) : _currentCase(NULL), _currentScale(1.0f, 1.0f), _position(0, 0)
{
	this->_texture_character.loadFromFile(filename);
}

IObject::~IObject()
{
}

void IObject::update()
{
	this->_character_sprite.setColor(DataContainer::getInstance()->clock.getColorOfDarkness());
}

void IObject::update(const sf::Color &color)
{
	sf::Color shadow = DataContainer::getInstance()->clock.getColorOfDarkness() - color;

	this->_character_sprite.setColor(shadow);
}

MapCase * IObject::getCurrentCase() const
{
	return this->_currentCase;
}

sf::Vector2f IObject::getScale() const
{
	return this->_currentScale;
}

void IObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Transform transform;

	if (this->_currentCase) {
		transform.translate(0, -DEPTH_SIZE * this->_currentCase->depth * RESIZE_TILE_Y);
	}

	target.draw(this->_character_sprite, transform);
}

void IObject::findCase()
{
	MapCase *currentCase = DataContainer::getInstance()->map->findTile(this->_position);
	if (currentCase) {
		currentCase->addObject(this);
	}

	this->_currentCase = currentCase;
}

sf::Vector2u IObject::getSizeTexture() const
{
	return this->_texture_character.getSize();
}
