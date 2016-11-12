#include "MusicManager.hpp"

MusicManager::MusicManager()
{
	int nb_music;

	for (nb_music = 0; music_constants[nb_music] != NO_MUSIC; ++nb_music) {
		this->musicBuffer_pool[music_constants[nb_music]] = "assets/musics/" + music_filename_constants[nb_music];
	}
}


MusicManager::~MusicManager()
{
}

void MusicManager::play(MusicConstants music_to_play)
{
	sf::Music *music = new sf::Music;

	if (!music->openFromFile(this->musicBuffer_pool[music_to_play])) {
		return;
	}

	music_pool.push_back(music);
	music->play();

	this->_currently_played[music_to_play] = std::prev(this->music_pool.end());
}

void MusicManager::update()
{
	for (std::map<MusicConstants, std::list<sf::Music *>::iterator >::iterator it = this->_currently_played.begin(); it != this->_currently_played.end();) {
		if ((*(it->second))->getStatus() == sf::SoundSource::Stopped) {
			delete (*(it->second));
			this->music_pool.erase(it->second);
			it = this->_currently_played.erase(it);
		}
		else {
			++it;
		}
	}
}


bool MusicManager::isPlaying(MusicConstants music_to_play)
{
	return this->_currently_played.find(music_to_play) != this->_currently_played.end();
}