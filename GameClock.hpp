#pragma once
#include	<SFML/Graphics.hpp>
#include	"Tool.hpp"

class GameClock : public sf::Drawable
{
public:
	GameClock();
	~GameClock();

	void			update(sf::Clock & clock);
	bool			isDebugEnable() const;
	void			setDebug(bool);
	int				getFrameNumber() const;
	int				getLastTotalFrame() const;
	const sf::Color	&getColorOfDarkness() const;

public:
	bool			is_paused;

private:
	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void			updateDayStatus();

private:
	bool			_debug;
	float			_time;
	float			_total_time;
	int				_frame;
	int				_lastTotalFrame;
	sf::Font		_font;
	sf::Text		_text;
	sf::View		_view;
	sf::Color		_darkness_of_day;
};

