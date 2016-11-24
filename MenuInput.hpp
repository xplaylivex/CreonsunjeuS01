#pragma once
#include "AClickable.hpp"
#include "AInputable.hpp"

class MenuInput : public AClickable, public AInputable
{
public:
	MenuInput();
	virtual ~MenuInput();
};

