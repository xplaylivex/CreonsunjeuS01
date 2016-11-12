#pragma once
#include <list>
#include <map>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Enum.hpp"
#include "DataContainer.hpp"
#include "Tool.hpp"

class DataContainer;

class KeyboardManager
{
public:
	KeyboardManager();
	~KeyboardManager();

	void		eventStorage(const sf::Event &);
	void		eventInterpreter();

	std::list<KeyConstants> getActions() const;
	sf::Keyboard::Key		getKey(const std::string &) const;
	void					assignKey(sf::Keyboard::Key);

/**
 * Method for the method pointer
 */
private:
	void		moveForward(void *) const;
	void		moveLeft(void *) const;
	void		moveBackward(void *) const;
	void		moveRight(void *) const;
	void		closeWindow(void *) const;
	void		zoom(void * data) const;
	void		unzoom(void * data) const;
	void		fire(void * data) const;
	void		ice(void * data) const;
	void		rocket(void * data) const;
	void		slime(void * data) const;

private:
	std::map<const std::string, sf::Keyboard::Key>					string_mapping;
	std::map<sf::Keyboard::Key, KeyConstants>						input_mapping;
	std::list<KeyConstants>											actions;
	std::map<KeyConstants, void (KeyboardManager::*)(void *) const> process_method_map;
};
