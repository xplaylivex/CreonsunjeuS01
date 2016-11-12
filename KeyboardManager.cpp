#include "KeyboardManager.hpp"

KeyboardManager::KeyboardManager()
{
	this->string_mapping["Z"] = sf::Keyboard::Z;
	this->string_mapping["Q"] = sf::Keyboard::Q;
	this->string_mapping["S"] = sf::Keyboard::S;
	this->string_mapping["D"] = sf::Keyboard::D;
	this->string_mapping["Up"] = sf::Keyboard::Up;
	this->string_mapping["Down"] = sf::Keyboard::Down;
	this->string_mapping["Left"] = sf::Keyboard::Left;
	this->string_mapping["Right"] = sf::Keyboard::Right;
	this->string_mapping["Escape"] = sf::Keyboard::Escape;
	this->string_mapping["Plus"] = sf::Keyboard::Add;
	this->string_mapping["Minus"] = sf::Keyboard::Subtract;

	this->input_mapping[sf::Keyboard::Z] = FORWARD;
	this->input_mapping[sf::Keyboard::Up] = FORWARD;
	this->input_mapping[sf::Keyboard::S] = BACKWARD;
	this->input_mapping[sf::Keyboard::Down] = BACKWARD;
	this->input_mapping[sf::Keyboard::Q] = LEFT;
	this->input_mapping[sf::Keyboard::Left] = LEFT;
	this->input_mapping[sf::Keyboard::D] = RIGHT;
	this->input_mapping[sf::Keyboard::Right] = RIGHT;
	this->input_mapping[sf::Keyboard::Escape] = ESCAPE;
	this->input_mapping[sf::Keyboard::Add] = PLUS;
	this->input_mapping[sf::Keyboard::Subtract] = MINUS;
	this->input_mapping[sf::Keyboard::Numpad1] = FIRE;
	this->input_mapping[sf::Keyboard::Numpad2] = ICE;
	this->input_mapping[sf::Keyboard::Numpad3] = ROCKET;
	this->input_mapping[sf::Keyboard::Numpad4] = SLIME;

	this->process_method_map[FORWARD] = &KeyboardManager::moveForward;
	this->process_method_map[BACKWARD] = &KeyboardManager::moveBackward;
	this->process_method_map[LEFT] = &KeyboardManager::moveLeft;
	this->process_method_map[RIGHT] = &KeyboardManager::moveRight;
	this->process_method_map[ESCAPE] = &KeyboardManager::closeWindow;
	this->process_method_map[PLUS] = &KeyboardManager::zoom;
	this->process_method_map[MINUS] = &KeyboardManager::unzoom;
	this->process_method_map[FIRE] = &KeyboardManager::fire;
	this->process_method_map[ICE] = &KeyboardManager::ice;
	this->process_method_map[ROCKET] = &KeyboardManager::rocket;
	this->process_method_map[SLIME] = &KeyboardManager::slime;
}

KeyboardManager::~KeyboardManager()
{
}

void KeyboardManager::eventStorage(const sf::Event &event)
{
	std::list<KeyConstants>::iterator ptr;

	if (event.type == sf::Event::KeyPressed) {
		for (std::map<sf::Keyboard::Key, KeyConstants>::iterator it = this->input_mapping.begin(); it != this->input_mapping.end(); ++it) {
			if (event.key.code == it->first && (ptr = find(this->actions.begin(), this->actions.end(), it->second)) == this->actions.end()) {
				this->actions.push_back(it->second);
				return;
			}
		}
	} else if (event.type == sf::Event::KeyReleased) {
		for (std::map<sf::Keyboard::Key, KeyConstants>::iterator it = this->input_mapping.begin(); it != this->input_mapping.end(); ++it) {
			if (event.key.code == it->first && (ptr = find(this->actions.begin(), this->actions.end(), it->second)) != this->actions.end()) {
				this->actions.erase(ptr);
				return;
			}
		}
	}
}

void KeyboardManager::eventInterpreter()
{
	for (std::list<KeyConstants>::iterator it = this->actions.begin(); it != this->actions.end(); ++it) {
		if (this->process_method_map.find(*it) != this->process_method_map.end()) {
			(*this.*process_method_map[*it])(NULL);
		}
	}
}

std::list<KeyConstants> KeyboardManager::getActions() const
{
	return this->actions;
}

sf::Keyboard::Key KeyboardManager::getKey(const std::string &key) const
{
	std::map<std::string, sf::Keyboard::Key>::const_iterator it = this->string_mapping.find(key);
	if (it != this->string_mapping.end()) {
		return it->second;
	}
	return sf::Keyboard::Home;
}

/**
 * Private
 * Method for the method pointer
 */

void KeyboardManager::moveForward(void *data) const
{
	sf::Vector2f future_coord = DataContainer::getInstance()->light.coord;
	MapCase *future_case = 0;

	future_coord.y -= 5.0f * (1.f / (float)DataContainer::getInstance()->clock.getLastTotalFrame());
	future_case = DataContainer::getInstance()->map->findTile(future_coord);
	if (future_case && future_case->can_collide && !Tool::collide_something(future_case, future_coord, true)) {
		DataContainer::getInstance()->light.coord = future_coord;
		DataContainer::getInstance()->main_character->move(DataContainer::getInstance()->light.coord);
	}
}

void KeyboardManager::moveLeft(void *data) const
{
	sf::Vector2f future_coord = DataContainer::getInstance()->light.coord;
	MapCase *future_case = 0;

	future_coord.x -= 5.0f * (1.f / (float)DataContainer::getInstance()->clock.getLastTotalFrame());
	future_case = DataContainer::getInstance()->map->findTile(future_coord);
	if (future_case && future_case->can_collide && !Tool::collide_something(future_case, future_coord, true)) {
		DataContainer::getInstance()->light.coord = future_coord;
		DataContainer::getInstance()->main_character->move(DataContainer::getInstance()->light.coord);
	}
}

void KeyboardManager::moveBackward(void *data) const
{
	sf::Vector2f future_coord = DataContainer::getInstance()->light.coord;
	MapCase *future_case = 0;

	future_coord.y += 5.0f * (1.f / (float)DataContainer::getInstance()->clock.getLastTotalFrame());
	future_case = DataContainer::getInstance()->map->findTile(future_coord);
	if (future_case && future_case->can_collide && !Tool::collide_something(future_case, future_coord, true)) {
		DataContainer::getInstance()->light.coord = future_coord;
		DataContainer::getInstance()->main_character->move(DataContainer::getInstance()->light.coord);
	}
}

void KeyboardManager::moveRight(void *data) const
{
	sf::Vector2f future_coord = DataContainer::getInstance()->light.coord;
	MapCase *future_case = 0;

	future_coord.x += 5.0f * (1.f / (float)DataContainer::getInstance()->clock.getLastTotalFrame());
	future_case = DataContainer::getInstance()->map->findTile(future_coord);
	if (future_case && future_case->can_collide && !Tool::collide_something(future_case, future_coord, true)) {
		DataContainer::getInstance()->light.coord = future_coord;
		DataContainer::getInstance()->main_character->move(DataContainer::getInstance()->light.coord);
	}
}

void KeyboardManager::closeWindow(void *data) const
{
	DataContainer::getInstance()->window.close();
}

void KeyboardManager::zoom(void *data) const
{
	sf::View v = DataContainer::getInstance()->window.getView();
	v.zoom(std::min(0.98f, 0.98f + (1.f / (float)DataContainer::getInstance()->clock.getLastTotalFrame())));
	DataContainer::getInstance()->window.setView(v);
}

void KeyboardManager::unzoom(void *data) const
{
	sf::View v = DataContainer::getInstance()->window.getView();
	v.zoom(1.02f + (1.f / (float)DataContainer::getInstance()->clock.getLastTotalFrame()));
	DataContainer::getInstance()->window.setView(v);
}

void KeyboardManager::fire(void *data) const
{
	if (!DataContainer::getInstance()->sound_manager.isPlaying(FIRE_SOUND)) {
		DataContainer::getInstance()->sound_manager.play(FIRE_SOUND);
	}
}

void KeyboardManager::ice(void *data) const
{
	if (!DataContainer::getInstance()->sound_manager.isPlaying(ICE_SOUND)) {
		DataContainer::getInstance()->sound_manager.play(ICE_SOUND);
	}
}

void KeyboardManager::rocket(void *data) const
{
	if (!DataContainer::getInstance()->sound_manager.isPlaying(ROCKET_SOUND)) {
		DataContainer::getInstance()->sound_manager.play(ROCKET_SOUND);
	}
}

void KeyboardManager::slime(void *data) const
{
	if (!DataContainer::getInstance()->sound_manager.isPlaying(SLIME_SOUND)) {
		DataContainer::getInstance()->sound_manager.play(SLIME_SOUND);
	}
}