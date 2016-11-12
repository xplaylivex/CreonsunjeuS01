#include "AFileManager.hpp"



AFileManager::AFileManager()
{
}


AFileManager::~AFileManager()
{
}

void AFileManager::closeFile()
{
	this->_file.close();
}

void AFileManager::trim(std::string &str)
{
	unsigned int begin;

	for (begin = 0; begin < str.size(); ++begin) {
		if (str[begin] != ' ' && str[begin] != '\t') {
			break;
		}
	}

	str.erase(0, begin);
}

std::string AFileManager::getValueFromKey(std::string &line, const std::string needle) const
{
	std::size_t found = line.find(needle);
	if (found != 0) {
		return "";
	}

	return line.substr(strlen(needle.c_str()));
}
