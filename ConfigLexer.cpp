#include "ConfigLexer.hpp"

#include <iostream>

ConfigLexer::ConfigLexer()
{
	const std::vector<sf::VideoMode> &video_modes = sf::VideoMode::getFullscreenModes();

	this->_config["RESOLUTION_WIDTH"] = std::to_string(video_modes.front().width);
	this->_config["RESOLUTION_HEIGHT"] = std::to_string(video_modes.front().height);
	this->_config["FULLSCREEN_ENABLED"] = std::to_string(sf::Style::Fullscreen);
	this->_config["KEYBOARD_FORWARD"] = "Z";
	this->_config["KEYBOARD_BACKWARD"] = "S";
	this->_config["KEYBOARD_LEFT"] = "Q";
	this->_config["KEYBOARD_RIGHT"] = "D";
	this->_config["KEYBOARD_QUIT"] = "Escape";
	this->_config["KEYBOARD_ZOOM"] = "Plus";
	this->_config["KEYBOARD_UNZOOM"] = "Minus";
	this->_config["KEYBOARD_ATTACK_1"] = "Numpad1";
	this->_config["KEYBOARD_ATTACK_2"] = "Numpad2";
	this->_config["KEYBOARD_ATTACK_3"] = "Numpad3";
	this->_config["KEYBOARD_ATTACK_4"] = "Numpad4";
	this->_config["SHOW_FPS"] = "0";
	this->_config["MUSIC_VOLUME"] = "100";
	this->_config["SOUND_VOLUME"] = "100";
}

ConfigLexer::~ConfigLexer()
{
}

void ConfigLexer::openFile(const std::string &filename)
{
	this->_file.open(filename, std::ios::in);
}

void ConfigLexer::process()
{
	std::string line;
	std::string value = "";

	if (this->_file.is_open()) {
		while (this->_file.good()) {
			std::getline(this->_file, line);
			this->trim(line);

			for (std::map<std::string, std::string>::iterator it = this->_config.begin(); it != this->_config.end(); ++it) {
				value = this->getValueFromKey(line, it->first + "=");
				if (value.size()) {
					this->_config[it->first] = value;
					break;
				}
			}
		}
	}
}

std::string ConfigLexer::getStringValue(const std::string key)
{
	std::map<std::string, std::string>::iterator it = this->_config.find(key);
	if (it != this->_config.end()) {
		return it->second;
	}
	return "";
}

int ConfigLexer::getNumberValue(const std::string key)
{
	std::map<std::string, std::string>::iterator it = this->_config.find(key);
	if (it != this->_config.end()) {
		return std::stoi(it->second);
	}
	return 0;
}

const std::map<std::string, std::string> &ConfigLexer::getConfig() const
{
	return this->_config;
}
