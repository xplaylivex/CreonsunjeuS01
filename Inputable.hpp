#pragma once
#include "ATrigger.hpp"

class Inputable : public ATrigger
{
public:
	Inputable();
	virtual ~Inputable();

public:
	virtual bool	isInputable() const;
	virtual bool	input(const sf::Event &);
};

