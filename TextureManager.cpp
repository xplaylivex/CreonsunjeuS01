#include "TextureManager.hpp"

TextureManager::TextureManager() : _texture_lexer(new TextureLexer)
{
	this->_texture_lexer->openFile("./config/texture_config.conf");
	this->_texture_lexer->process();
}

TextureManager::~TextureManager()
{
	delete _texture_lexer;
}

std::vector<sf::Texture*>& TextureManager::getSetTexture()
{
	return this->_texture_lexer->getLoadedSet();
}

void TextureManager::loadSet(const std::string str)
{
	this->_texture_lexer->loadSet(str);
}
