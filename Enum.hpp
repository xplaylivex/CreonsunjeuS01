#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

enum KeyConstants {
	NOTHING = 0,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	ESCAPE,
	PLUS,
	MINUS,
	FIRE,
	ICE,
	ROCKET,
	SLIME
};

enum SoundConstants {
	NO_SOUND = 0,
	FIRE_SOUND,
	ICE_SOUND,
	ROCKET_SOUND,
	SLIME_SOUND
};

enum MusicConstants {
	NO_MUSIC = 0,
	MUSIC_DEFAULT
};

extern SoundConstants							sound_constants[];
extern std::string								sound_filename_constants[];
extern MusicConstants							music_constants[];
extern std::string								music_filename_constants[];