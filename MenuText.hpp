#pragma once
#include <SFML/Graphics.hpp>
#include "ABasicElement.hpp"
#include "DataContainer.hpp"

class MenuText : public ABasicElement
{
public:
	MenuText(const std::string, const sf::Vector2i, const sf::Vector2i);
	virtual ~MenuText();

public:
	void			changeText(const std::string &);
	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Text	_text;
	std::string	_currentText;
	sf::Font	_font;
};

