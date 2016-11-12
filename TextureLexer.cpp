#include "TextureLexer.hpp"

TextureLexer::TextureLexer() : AFileManager()
{
}

TextureLexer::~TextureLexer()
{
}

void TextureLexer::openFile(const std::string &filename)
{
	this->_file.open(filename, std::ios::in);
}

void TextureLexer::process()
{
	std::string tmp_set;
	std::string line;
	std::string current_set = "";

	if (this->_file.is_open()) {
		while (this->_file.good()) {
			std::getline(this->_file, line);
			this->trim(line);

			tmp_set = this->getValueFromKey(line, TEXTURE_SET_NAME);
			if (!tmp_set.empty()) {
				current_set = tmp_set;
			} else if (!current_set.empty()) {
				this->lex_resources(line, current_set);
			}
		}
	}
}

void TextureLexer::lex_resources(std::string & filename, const std::string &key_name)
{
	std::ifstream file(filename.c_str());

	if (!file.fail()) {
		this->_texture_config[key_name].push_back(filename);
	}
}

void TextureLexer::loadSet(const std::string str)
{
	if (this->_texture_config.find(str) != this->_texture_config.end()) {
		for (std::vector<sf::Texture *>::iterator it = this->_loaded_texture.begin(); it != this->_loaded_texture.end(); ++it) {
			delete *it;
		}

		this->_loaded_texture.clear();

		for (std::vector<std::string>::iterator it = this->_texture_config[str].begin(); it != this->_texture_config[str].end(); ++it) {
			sf::Texture *texture = new sf::Texture();

			if (texture->loadFromFile(*it)) {
				this->_loaded_texture.push_back(texture);
			}
			else {
				delete texture;
			}
		}
	}
}

std::vector<sf::Texture*> &TextureLexer::getLoadedSet()
{
	return this->_loaded_texture;
}
