#include "AWindow.hpp"
#include <iostream>

AWindow::AWindow(const unsigned char flag, const sf::Vector2f position, const sf::Vector2f size)
	: ABasicElement(FLAG_EVENT::CLOSED_WINDOW | flag), _background(size), _to_close(WINDOW_DEFAULT)
{
	this->_background.setPosition(position);
	this->_background.setFillColor(sf::Color::Red);
}

AWindow::~AWindow()
{
	std::cout << "Destructeur awindow" << std::endl;
}

bool AWindow::isDeletable()
{
	return this->_to_close == WINDOW_TO_DELETE;
}
