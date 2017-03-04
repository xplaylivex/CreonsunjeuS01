#pragma once
#include "ATrigger.hpp"

class Selectable : public ATrigger
{
public:
	Selectable();
	virtual ~Selectable();

public:
	virtual bool	isSelectable() const;
	virtual bool	select(const sf::Event &);
};