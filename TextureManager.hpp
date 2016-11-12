#pragma once
#include <SFML/Graphics.hpp>
#include "Enum.hpp"
#include "TextureLexer.hpp"

class TextureLexer;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

public:
	std::vector<sf::Texture *>	&getSetTexture();
	void						loadSet(const std::string);

private:
	TextureLexer				*_texture_lexer;
};

