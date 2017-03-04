#include "MenuTextButton.hpp"
#include <iostream>

MenuTextButton::MenuTextButton(const std::string text, const sf::Vector2f position, const sf::Vector2f size)
	: _background(size)
{
	this->setPosition(sf::Vector2i(position.x, position.y));
	this->setSize(sf::Vector2i(size.x, size.y));

	// TODO : police en cache
	if (!this->_font.loadFromFile("arial.ttf")) {
		std::cerr << "Error while opening the font for debug" << std::endl;
		exit(-1);
	}
	this->_text.setFont(this->_font);

	this->_text.setPosition(position.x + 15, position.y + 15);
	this->_text.setString(text);
	this->_text.setCharacterSize(20);
	this->_text.setFillColor(sf::Color::White);

	this->_background.setPosition(position);
	this->_background.setFillColor(sf::Color::Blue);
}

MenuTextButton::~MenuTextButton()
{
}

void MenuTextButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->_background);
	target.draw(this->_text);
}