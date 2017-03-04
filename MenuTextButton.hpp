#pragma once
#include "AButton.hpp"

class MenuTextButton : public AButton
{
public:
	MenuTextButton(const std::string text = "", const sf::Vector2f position = sf::Vector2f(), const sf::Vector2f size = sf::Vector2f());
	virtual ~MenuTextButton();

public:
	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::RectangleShape	_background;
	sf::Text			_text;
	sf::Font			_font;
};