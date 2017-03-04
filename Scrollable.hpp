#pragma once
#include "ATrigger.hpp"

class Scrollable : public ATrigger
{
public:
	Scrollable();
	virtual ~Scrollable();

public:
	virtual bool	isScrollable() const;
	virtual bool	scroll(const sf::Event &);
};

