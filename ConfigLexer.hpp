#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "AFileManager.hpp"

class AFileManager;

class ConfigLexer : public AFileManager
{
public:
	ConfigLexer();
	virtual ~ConfigLexer();

public:
	virtual void						openFile(const std::string &);
	void								process();

public:
	std::string							getStringValue(const std::string);
	int									getNumberValue(const std::string);

	const std::map<std::string, std::string>& getConfig() const;

private:
	std::map<std::string, std::string>	_config;
};