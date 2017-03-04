#include "ClosedWindow.hpp"
#include <iostream>

ClosedWindow::ClosedWindow()
{
}

ClosedWindow::ClosedWindow(const sf::Vector2f position, const sf::Vector2f size) : _to_close(WINDOW_DEFAULT), _background(size)
{
	this->_background.setPosition(position);
	this->_background.setFillColor(sf::Color::Red);
	// TODO : set the background (repetable)
}

ClosedWindow::~ClosedWindow()
{
	std::cout << "closed window delete" << std::endl;
}

bool ClosedWindow::isWindow() const
{
	return true;
}
/*
bool ClosedWindow::isDeletable() const
{
	return this->_to_close == WINDOW_TO_DELETE;
}*/

bool ClosedWindow::close(const sf::Event &event)
{
	return this->_callback(event);
}