#include "DataContainer.hpp"
#include <iostream>
DataContainer *DataContainer::_instance;


DataContainer::DataContainer() : map(NULL), keyboard(NULL), load_manager(new LoadManager())
{
	this->config_lexer.openFile("config/general_config.conf");
	this->config_lexer.process();

	this->clock.setDebug(this->config_lexer.getNumberValue("SHOW_FPS") == 0 ? false : true);
	this->sound_manager.setVolume(this->config_lexer.getNumberValue("SOUND_VOLUME"));
	this->music_manager.setVolume(this->config_lexer.getNumberValue("MUSIC_VOLUME"));
}

DataContainer & DataContainer::operator=(const DataContainer &old_data)
{
	this->light.coord = old_data.light.coord;
	this->map = old_data.map;

	return *this;
}

DataContainer::DataContainer(const DataContainer &old_data)
{
	this->light.coord = old_data.light.coord;
	this->map = old_data.map;
}

DataContainer::~DataContainer()
{
	if (DataContainer::_instance) {
		delete DataContainer::_instance;
	}
}

DataContainer *DataContainer::getInstance()
{
	if (!DataContainer::_instance) {
		DataContainer::_instance = new DataContainer();
	}

	return DataContainer::_instance;
}

void		DataContainer::init(std::list<MapCase*> *list)
{
	this->window.create(
		sf::VideoMode(this->config_lexer.getNumberValue("RESOLUTION_WIDTH"), this->config_lexer.getNumberValue("RESOLUTION_HEIGHT")),
		WINDOW_NAME,
		this->config_lexer.getNumberValue("FULLSCREEN_ENABLED")
	);
	this->map = new IsometricMap(list);
	this->keyboard = new KeyboardManager(this->config_lexer.getConfig());
	this->main_character = new CharacterSprite();
	//this->music_manager.play(MUSIC_DEFAULT);
	this->_updateView();

	// TODO : TO DELETE LATER
	char toto = rand() % 20 + 1;
	for (char i = 0; i < toto; ++i) {
		this->npcs.push_back(new NPC());
	}
	toto = rand() % 20 + 1;
	for (char i = 0; i < toto; ++i) {
		this->items.push_back(new Item());
	}
}

void DataContainer::draw()
{
	this->window.clear();
	this->map->renderMap(this->window, this->light);

	if (this->clock.isDebugEnable()) {
		this->window.draw(this->clock);
	}
}

void DataContainer::update()
{
	this->keyboard->eventInterpreter();
	this->main_character->update();
	this->main_character->findCase();
	this->main_character->changeOrientation(this->keyboard->getActions());
	this->_updateView();
	this->music_manager.update();
	this->sound_manager.update();
}

sf::Vector2i DataContainer::getMinCoordBound() const
{
	return this->_minCoordBounds;
}

sf::Vector2i DataContainer::getMaxCoordBound() const
{
	return this->_maxCoordBounds;
}

void DataContainer::_updateView()
{
	sf::View view = this->window.getView();
	view.setCenter(Tool::toWindowCoord(this->light.coord.x, this->light.coord.y));
	this->window.setView(view);

	sf::Vector2i tmp_up_left = Tool::toDataCoord(view.getCenter().x - (view.getSize().x / 2), view.getCenter().y - (view.getSize().y / 2), false);
	sf::Vector2i tmp_up_right = Tool::toDataCoord(view.getCenter().x + (view.getSize().x / 2), view.getCenter().y - (view.getSize().y / 2), false);
	sf::Vector2i tmp_down_right = Tool::toDataCoord(view.getCenter().x + (view.getSize().x / 2), view.getCenter().y + (view.getSize().y / 2), false);
	sf::Vector2i tmp_down_left = Tool::toDataCoord(view.getCenter().x - (view.getSize().x / 2), view.getCenter().y + (view.getSize().y / 2), false);

	this->_minCoordBounds = sf::Vector2i(tmp_up_left.x - 1, tmp_up_right.y - 1);
	this->_maxCoordBounds = sf::Vector2i(tmp_down_right.x + 1, tmp_down_left.y + 1);
}