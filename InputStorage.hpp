#pragma once
#include <algorithm>
#include <list>
#include <queue>
#include <SFML\Graphics.hpp>

class InputStorage
{
public:
	InputStorage();
	~InputStorage();

public:
	bool						addEvent(sf::Event &);
	void						cleanScroll();
	const std::list<sf::Event>	&getKeyEventsForKeyboard() const;
	std::queue<sf::Event>		&getKeyEvents();
	std::queue<sf::Event>		&getClickEvents();
	sf::Event					*getScrollEvent();

private:
	void						_manageKeyInput(sf::Event &);
	void						_manageClickInput(sf::Event &);
	void						_manageScrollInput(sf::Event &);

private:
	// useless ?
	std::list<sf::Event>		_storage_key;
	std::list<sf::Event>		_storage_click;
	sf::Event					*_storage_scroll;

	std::queue<sf::Event>		_key_to_process;
	std::queue<sf::Event>		_click_to_process;
	sf::Event					*_scroll_to_process;
};

