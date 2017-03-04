#pragma once
#include "ACharacter.hpp"
#include "AWindow.hpp"
#include "MenuText.hpp"
#include "MenuImage.hpp"
#include "DataContainer.hpp"
#include "Tool.hpp"

class MenuWindowDialog : public AWindow
{
public:
	MenuWindowDialog(ACharacter *, ACharacter *, std::vector<std::string> &);
	virtual ~MenuWindowDialog();

public:
	virtual void						draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	bool								_nextText();

private:
	std::vector<std::string>			&_texts;
	/*std::vector<std::string>::iterator*/int	_index;
	MenuText							_dialog_text;
	MenuImage							_dialog_character_one;
	MenuImage							_dialog_character_two;
};

