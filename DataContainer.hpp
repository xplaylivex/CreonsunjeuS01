#pragma once
#include <SFML/Graphics.hpp>
#include "CharacterSprite.hpp"
#include "ConfigLexer.hpp"
#include "IsometricMap.hpp"
#include "GameClock.hpp"
#include "GlobalLight.hpp"
#include "Item.hpp"
#include "KeyboardManager.hpp"
#include "LoadManager.hpp"
#include "MusicManager.hpp"
#include "NPC.hpp"
#include "SoundManager.hpp"
#include "TextureManager.hpp"

class CharacterSprite;
class ConfigLexer;
class GameClock;
class GlobalLight;
class IsometricMap;
class KeyboardManager;
class LoadManager;
class MusicManager;
class SoundManager;
class TextureManager;

class DataContainer
{
public:
	static DataContainer	*getInstance();

	void			init(std::list<MapCase*> *);
	void			update();
	void			draw();

	sf::Vector2i	getMinCoordBound() const;
	sf::Vector2i	getMaxCoordBound() const;

public:
	sf::RenderWindow		window;
	ConfigLexer				config_lexer;
	GlobalLight				light;
	IsometricMap			*map;
	CharacterSprite			*main_character;
	KeyboardManager			*keyboard;
	GameClock				clock;
	LoadManager				*load_manager;
	TextureManager			texture_manager;
	SoundManager			sound_manager;
	MusicManager			music_manager;
	std::list<NPC *>		npcs;
	std::list<Item *>		items;

private:
	DataContainer();
	~DataContainer();
	DataContainer(const DataContainer &);
	DataContainer &operator=(const DataContainer &);

	void			_updateView();

private:
	sf::Vector2i			_minCoordBounds;
	sf::Vector2i			_maxCoordBounds;

	static DataContainer	*_instance;
};