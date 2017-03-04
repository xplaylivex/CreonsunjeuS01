#include "MenuManager.hpp"

#include <iostream>

MenuManager::MenuManager()
{
}

MenuManager::~MenuManager()
{
}

bool MenuManager::processEvents(InputStorage &input_store)
{
	std::queue<sf::Event>	&key_list		= input_store.getKeyEvents();
	std::queue<sf::Event>	&click_list		= input_store.getClickEvents();
	sf::Event				*scroll_event	= input_store.getScrollEvent();

	for (std::list<ABasicElement *>::iterator it = this->_menu_elements.begin(); it != this->_menu_elements.end();) {
		if (click_list.size() && (*it)->isClickable()) {
			sf::Event e = click_list.front();

			// For the Mouse
			if ((*it)->click(e)) {
				ABasicElement *tmp = *it;

				this->_already_process.push_back((*it));
				it = this->_menu_elements.erase(it);

				click_list.pop();

				if (tmp->doClose()) {
					return true;
				}

				continue;
			}
		}
		if (key_list.size() && (*it)->isInputable()) {
			sf::Event		e = key_list.front();

			// For the Input
			if ((*it)->input(e)) {
				ABasicElement	*tmp = *it;

				this->_already_process.push_back((*it));
				it = this->_menu_elements.erase(it);

				key_list.pop();

				if (tmp->doClose()) {
					return true;
				}
				continue;
			}
		}
		if ((*it)->isScrollable() && scroll_event) {
			// For the Scroll
			if ((*it)->scroll(*scroll_event)) {
				this->_already_process.push_back((*it));
				it = this->_menu_elements.erase(it);

				scroll_event = NULL;
				continue;
			}
		}
		
		++it;
	}

	while (key_list.size())		{ key_list.pop();	}
	while (click_list.size())	{ click_list.pop(); }

	return false;
}

void MenuManager::clearWindows()
{
	for (std::list<ABasicElement *>::iterator it = this->_already_process.begin(); it != this->_already_process.end();) {
		if ((*it)->isWindow() && dynamic_cast<AWindow *>(*it)->isDeletable()) {
			delete (*it);
			it = this->_already_process.erase(it);
		} else {
			++it;
		}
	}
}

bool MenuManager::resetWindows()
{
	for (std::list<ABasicElement *>::iterator it = this->_already_process.begin(); it != this->_already_process.end();) {
		this->_menu_elements.push_back((*it));
		it = this->_already_process.erase(it);
	}
	return false;
}

void MenuManager::draw()
{
	for (std::list<ABasicElement *>::iterator it = this->_menu_elements.begin(); it != this->_menu_elements.end();++it) {
		if ((*it)->isWindow()) {
			DataContainer::getInstance()->window.draw(**it);
		}
	}
	for (std::list<ABasicElement *>::iterator it = this->_already_process.begin(); it != this->_already_process.end();++it) {
		if ((*it)->isWindow()) {
			DataContainer::getInstance()->window.draw(**it);
		}
	}
}
