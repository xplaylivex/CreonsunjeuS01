#include "InputStorage.hpp"
#include <iostream>

InputStorage::InputStorage()
{
}


InputStorage::~InputStorage()
{
}

bool InputStorage::addEvent(sf::Event &event)
{
	if (event.type == sf::Event::Closed) {
		return false;
	} else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
		this->_manageKeyInput(event);
	} else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased) {
		this->_manageClickInput(event);
	} else {
		this->_manageScrollInput(event);
	}
	return true;
}

void InputStorage::cleanScroll()
{
	this->_storage_scroll = NULL;
	this->_scroll_to_process = NULL;
}

const std::list<sf::Event>& InputStorage::getKeyEventsForKeyboard() const
{
	return this->_storage_key;
}

std::queue<sf::Event>&		InputStorage::getKeyEvents()
{
	return this->_key_to_process;
}

std::queue<sf::Event>&		InputStorage::getClickEvents()
{
	return this->_click_to_process;
}

sf::Event					*InputStorage::getScrollEvent()
{
	return this->_scroll_to_process;
}

void InputStorage::_manageKeyInput(sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed) {
		for (std::list<sf::Event>::iterator it = this->_storage_key.begin(); it != this->_storage_key.end(); ++it) {
			if (event.key.code == it->key.code) {
				return;
			}
		}
		this->_storage_key.push_back(event);
	} else if (event.type == sf::Event::KeyReleased) {
		for (std::list<sf::Event>::iterator it = this->_storage_key.begin(); it != this->_storage_key.end(); ++it) {
			if (event.key.code == it->key.code) {
				this->_storage_key.erase(it);
				this->_key_to_process.push(event);
				return;
			}
		}
	}
}

void InputStorage::_manageClickInput(sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		for (std::list<sf::Event>::iterator it = this->_storage_click.begin(); it != this->_storage_click.end(); ++it) {
			if (event.mouseButton.button == it->mouseButton.button) {
				return;
			}
		}
		this->_storage_click.push_back(event);
	} else if (event.type == sf::Event::MouseButtonReleased) {
		for (std::list<sf::Event>::iterator it = this->_storage_click.begin(); it != this->_storage_click.end(); ++it) {
			if (event.mouseButton.button == it->mouseButton.button) {
				this->_storage_click.erase(it);
				this->_click_to_process.push(event);
				return;
			}
		}
	}
}

void InputStorage::_manageScrollInput(sf::Event &event)
{
	if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.wheel == sf::Mouse::Wheel::VerticalWheel) {
		this->_storage_scroll = &event;
		this->_scroll_to_process = &event;
	}
}