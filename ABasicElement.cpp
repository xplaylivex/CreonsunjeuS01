#include "ABasicElement.hpp"
#include <iostream>

ABasicElement::ABasicElement(const unsigned char flag)
	: _do_close(false), _click_trigger(NULL), _input_trigger(NULL), _scroll_trigger(NULL), _select_trigger(NULL), _window_trigger(NULL)
{
	if (flag & FLAG_EVENT::CLICKABLE) {
		this->_click_trigger = new Clickable();
	}
	if (flag & FLAG_EVENT::INPUTABLE) {
		this->_input_trigger = new Inputable();
	}
	if (flag & FLAG_EVENT::SCROLLABLE) {
		this->_scroll_trigger = new Scrollable();
	}
	if (flag & FLAG_EVENT::SELECTABLE) {
		this->_select_trigger = new Selectable();
	}
	if (flag & FLAG_EVENT::CLOSED_WINDOW) {
		this->_window_trigger = new ClosedWindow();
	}
}

ABasicElement::~ABasicElement()
{
	if (this->_click_trigger) {
		delete this->_click_trigger;
	}
	if (this->_input_trigger) {
		delete this->_input_trigger;
	}
	if (this->_scroll_trigger) {
		delete this->_scroll_trigger;
	}
	if (this->_select_trigger) {
		delete this->_select_trigger;
	}
	if (this->_window_trigger) {
		delete this->_window_trigger;
	}
	for (std::vector<ABasicElement *>::iterator it = this->children.begin(); it != this->children.end();) {
		delete (*it);
		it = this->children.erase(it);
	}
}

/* Get & Set */

sf::Vector2i ABasicElement::getPosition() const
{
	return this->_position;
}

void ABasicElement::setPosition(const sf::Vector2i &position)
{
	this->_position.x = position.x;
	this->_position.y = position.y;
}

sf::Vector2i ABasicElement::getSize() const
{
	return this->_size;
}

void ABasicElement::setSize(const sf::Vector2i &size)
{
	this->_size.x = size.x;
	this->_size.y = size.y;
}

void ABasicElement::setCallback(const unsigned char flag, std::function<bool(const sf::Event &)> callback)
{
	if (flag & FLAG_EVENT::CLICKABLE) {
		this->_click_trigger->setCallback(callback);
	}
	if (flag & FLAG_EVENT::INPUTABLE) {
		this->_input_trigger->setCallback(callback);
	}
	if (flag & FLAG_EVENT::SCROLLABLE) {
		this->_scroll_trigger->setCallback(callback);
	}
	if (flag & FLAG_EVENT::SELECTABLE) {
		this->_select_trigger->setCallback(callback);
	}
	if (flag & FLAG_EVENT::CLOSED_WINDOW) {
		this->_window_trigger->setCallback(callback);
	}
}

void ABasicElement::setClickHitbox(const sf::Vector2f position, const sf::Vector2f size)
{
	if (this->_click_trigger) {
		this->_click_trigger->setHitbox(position, size);
	}
}

/* is... */

bool ABasicElement::doClose() const
{
	return this->_do_close;
}

bool ABasicElement::isClickable() const
{
	return this->_click_trigger != NULL;
}

bool ABasicElement::isSelectable() const
{
	return this->_select_trigger != NULL;
}

bool ABasicElement::isWindow() const
{
	return this->_window_trigger != NULL;
}

bool ABasicElement::isScrollable() const
{
	return this->_scroll_trigger != NULL;
}

bool ABasicElement::isInputable() const
{
	return this->_input_trigger != NULL;
}

/* Event */

bool ABasicElement::click(const sf::Event &event)
{
	return this->_click_trigger->click(event);
}

bool ABasicElement::input(const sf::Event &event)
{
	return this->_input_trigger->input(event);
}

bool ABasicElement::scroll(const sf::Event &event)
{
	return this->_scroll_trigger->scroll(event);
}

bool ABasicElement::select(const sf::Event &event)
{
	return this->_select_trigger->select(event);
}

bool ABasicElement::closedWindow(const sf::Event &event)
{
	return this->_window_trigger->close(event);
}