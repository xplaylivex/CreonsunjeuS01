#pragma once
#include <SFML\Graphics.hpp>
#include <functional>

class ATrigger
{
public:
	ATrigger();
	virtual ~ATrigger();

	void setCallback(const std::function<bool(const sf::Event &)> &);

protected:
	std::function<bool(const sf::Event &)> _callback;
};

