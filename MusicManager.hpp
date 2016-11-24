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
	void setVolume(int);

private:
	int												_volume;
	std::map<MusicConstants, std::string>			_musicBuffer_pool;
	std::list<sf::Music *>							_music_pool;
	std::map<MusicConstants, std::list<sf::Music *>::iterator>	_currently_played;
};