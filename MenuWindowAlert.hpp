#pragma once
#include "AWindow.hpp"
#include "DataContainer.hpp"
#include "MenuTextButton.hpp"

class MenuWindowAlert : public AWindow
{
public:
	MenuWindowAlert();
	virtual ~MenuWindowAlert();

public:
	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	bool			_is_displayed;
	MenuTextButton	_resume;
	MenuTextButton	_exit;
};

