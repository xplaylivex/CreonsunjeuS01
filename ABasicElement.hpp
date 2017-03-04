#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "Enum.hpp"
#include "Clickable.hpp"
#include "Inputable.hpp"
#include "Scrollable.hpp"
#include "Selectable.hpp"
#include "ClosedWindow.hpp"

class ABasicElement : public sf::Drawable
{
public:
	ABasicElement(const unsigned char flag);
	virtual ~ABasicElement();

public:
	sf::Vector2i	getPosition() const;
	void			setPosition(const sf::Vector2i &);
	sf::Vector2i	getSize() const;
	void			setSize(const sf::Vector2i & size);
	void			setCallback(const unsigned char flag, std::function<bool (const sf::Event &)> callback);
	void			setClickHitbox(const sf::Vector2f position, const sf::Vector2f size);

public:
	bool			doClose() const;
	virtual bool	isClickable() const;
	virtual bool	isInputable() const;
	virtual bool	isScrollable() const;
	virtual bool	isSelectable() const;
	virtual bool	isWindow() const;

public:
	virtual bool	click(const sf::Event &);
	virtual bool	input(const sf::Event &);
	virtual bool	scroll(const sf::Event &);
	virtual bool	select(const sf::Event &);
	virtual bool	closedWindow(const sf::Event &);

public:
	ABasicElement					*parent;
	std::vector<ABasicElement *>	children;

protected:
	sf::Vector2i	_position;
	sf::Vector2i	_size;
	bool			_do_close;

private:
	Clickable		*_click_trigger;
	Inputable		*_input_trigger;
	Scrollable		*_scroll_trigger;
	Selectable		*_select_trigger;
	ClosedWindow	*_window_trigger;
};

