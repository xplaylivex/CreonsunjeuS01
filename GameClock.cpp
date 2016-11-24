#include "GameClock.hpp"
#include <iostream>


GameClock::GameClock() : is_paused(false), _debug(false), _time(0), _total_time(0), _frame(0), _lastTotalFrame(std::numeric_limits<int>::max()), _darkness_of_day(sf::Color::White)
{
	if (!this->_font.loadFromFile("arial.ttf")) {
		std::cerr << "Error while opening the font for debug" << std::endl;
		exit(-1);
	}
	this->_text.setFont(this->_font);
	this->_text.setCharacterSize(20);
	this->_text.setFillColor(sf::Color::White);
	this->_view.setCenter(0, 0);
	this->_text.setPosition(-75, -25);
	this->_view.setSize(200, 50);
	this->_view.setViewport(sf::FloatRect(0.0f, 0.0f, 0.13f, 0.05f));
	this->_text.setString("--- FPS");
}

GameClock::~GameClock()
{
}

void		GameClock::update(sf::Clock &clock) {
	float ms_passed = clock.restart().asSeconds();

	this->_frame++;
	this->_time += ms_passed;
	if (!this->is_paused) {
		this->_total_time += ms_passed;
	}

	if (this->_time > 1.0f) {
		this->_text.setString(std::to_string(this->_frame) + "FPS");
		this->_lastTotalFrame = std::max(this->_frame, 1);
		this->_frame = 0;
		this->_time = 0.0f;
	}

	if ((int)(this->_total_time) % 10 == 0) {
		this->updateDayStatus();
	}
}

bool GameClock::isDebugEnable() const
{
	return this->_debug;
}

void GameClock::setDebug(bool enabled)
{
	this->_debug = enabled;
}

int GameClock::getFrameNumber() const
{
	return this->_frame;
}

int GameClock::getLastTotalFrame() const
{
	return this->_lastTotalFrame;
}

const sf::Color & GameClock::getColorOfDarkness() const
{
	return this->_darkness_of_day;
}

void GameClock::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (this->isDebugEnable()) {
		sf::View	v = target.getView();

		target.setView(this->_view);
		target.draw(this->_text);

		target.setView(v);
	}
}

void GameClock::updateDayStatus()
{
	unsigned char color = 255 - Tool::getPercentageDarknessFromTime(this->_total_time) * 80;

	this->_darkness_of_day.r = color;
	this->_darkness_of_day.g = color;
	this->_darkness_of_day.b = color;
}
