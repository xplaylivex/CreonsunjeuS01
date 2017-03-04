#pragma once
#include "ABasicElement.hpp"

class AWindow : public ABasicElement
{
public:
	AWindow(const unsigned char flag = FLAG_EVENT::EVENT_NOTHING, const sf::Vector2f position = sf::Vector2f(), const sf::Vector2f size = sf::Vector2f());
	virtual ~AWindow();

public:
	bool isDeletable();

protected:
	sf::RectangleShape	_background;
	unsigned char		_to_close;
	sf::View			_view;
};

