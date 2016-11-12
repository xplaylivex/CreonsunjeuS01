#include "SoundManager.hpp"

#include <iostream>

SoundManager::SoundManager()
{
	int nb_sound;

	for (nb_sound = 0; sound_constants[nb_sound] != NO_SOUND; ++nb_sound) {
		this->_soundBuffer_pool[sound_constants[nb_sound]] = new sf::SoundBuffer();
		this->_soundBuffer_pool[sound_constants[nb_sound]]->loadFromFile("assets/sounds/" + sound_filename_constants[nb_sound]);
	}
}


SoundManager::~SoundManager()
{
}

void SoundManager::play(SoundConstants sound_to_play)
{
	sf::Sound *sound = new sf::Sound;

	sound->setBuffer(*(this->_soundBuffer_pool[sound_to_play]));
	this->_sound_pool.push_back(sound);
	sound->play();

	this->_currently_played[sound_to_play] = std::prev(this->_sound_pool.end());
}

void SoundManager::update()
{
	for (std::map<SoundConstants, std::list<sf::Sound *>::iterator >::iterator it = this->_currently_played.begin(); it != this->_currently_played.end();) {
		if ((*(it->second))->getStatus() == sf::SoundSource::Stopped) {
			delete (*(it->second));
			this->_sound_pool.erase(it->second);
			it = this->_currently_played.erase(it);
		} else {
			++it;
		}
	}
}


bool SoundManager::isPlaying(SoundConstants sound_to_play)
{
	return this->_currently_played.find(sound_to_play) != this->_currently_played.end();
}
