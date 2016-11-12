#pragma once
#include <SFML/Audio.hpp>
#include <algorithm>
#include <map>
#include <list>
#include "Enum.hpp"

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void play(SoundConstants);
	void update();
	bool isPlaying(SoundConstants);

private:
	std::map<SoundConstants, sf::SoundBuffer *>					_soundBuffer_pool;
	std::list<sf::Sound *>										_sound_pool;
	std::map<SoundConstants, std::list<sf::Sound *>::iterator>	_currently_played;
};

