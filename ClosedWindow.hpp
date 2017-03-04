#pragma once
#include "ATrigger.hpp"
#include "Tool.hpp"

class ClosedWindow : public ATrigger
{
public:
	ClosedWindow();
	ClosedWindow(const sf::Vector2f, const sf::Vector2f);
	virtual ~ClosedWindow();
	virtual bool	isWindow() const;
	//virtual bool	isDeletable() const;

	bool			close(const sf::Event & event);

protected:
	unsigned char		_to_close;
	sf::RectangleShape	_background;
};

