#include "MenuText.hpp"

MenuText::MenuText(const std::string text, const sf::Vector2i position, const sf::Vector2i size) : ABasicElement(FLAG_EVENT::EVENT_NOTHING)
{
	// TODO : police en cache
	if (!this->_font.loadFromFile("arial.ttf")) {
		std::cerr << "Error while opening the font for debug" << std::endl;
		exit(-1);
	}
	this->_text.setFont(this->_font);

	this->setPosition(position);
	this->setSize(size);
	this->_text.setPosition(position.x, position.y);
	this->_text.setString(text);
	this->_text.setCharacterSize(20);
	this->_text.setFillColor(sf::Color::White);
}

MenuText::~MenuText()
{
	std::cout << "menu text delete" << std::endl;
}

void MenuText::changeText(const std::string &text)
{
	this->_currentText = text;
	this->_text.setString(text);
}

void MenuText::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->_text);
}
