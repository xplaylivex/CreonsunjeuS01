#include "ConfigLexer.hpp"

ConfigLexer::ConfigLexer()
{
	const std::vector<sf::VideoMode> &video_modes = sf::VideoMode::getFullscreenModes();

	this->_config["RESOLUTION_WIDTH"] = std::to_string(video_modes.front().width);
	this->_config["RESOLUTION_HEIGHT"] = std::to_string(video_modes.front().height);
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
