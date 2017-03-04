#pragma once
#include "ATrigger.hpp"

class Clickable : public ATrigger
{
public:
	Clickable();
	Clickable(const sf::Vector2i &position, const sf::Vector2i &size);
	virtual ~Clickable();

public:
	virtual bool	isClickable() const;
	virtual bool	click(const sf::Event &);
	bool			isClicked(const sf::Vector2f & position) const;
	void			setHitbox(const sf::Vector2f &position, const sf::Vector2f &size);

private:
	sf::FloatRect	_hitbox;
};

