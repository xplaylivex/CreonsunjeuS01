#pragma once
#include <map>
#include <vector>
#include <list>
#include <string>
#include "AFileManager.hpp"
#include "Tool.hpp"

class TextureLexer : public AFileManager
{
public:
	TextureLexer();
	virtual ~TextureLexer();

public:
	virtual void				openFile(const std::string &);
	void						process();
	std::vector<sf::Texture *>	&getLoadedSet();
	void						loadSet(const std::string);

private:
	void						lex_resources(std::string &, const std::string &);

private:
	std::vector<sf::Texture *>	_loaded_texture;
	std::map<std::string, std::vector<std::string> > _texture_config;
};