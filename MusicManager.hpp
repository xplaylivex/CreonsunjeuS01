#pragma once
#include <SFML/Audio.hpp>
#include <map>
#include <list>
#include "Enum.hpp"

class MusicManager
{
public:
	MusicManager();
	~MusicManager();

	void play(MusicConstants);
	void update();
	bool isPlaying(MusicConstants);

public:
	std::map<MusicConstants, std::string>			musicBuffer_pool;
	std::list<sf::Music *>							music_pool;
	std::map<MusicConstants, std::list<sf::Music *>::iterator>	_currently_played;
};