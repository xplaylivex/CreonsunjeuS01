#include "LoadManager.hpp"
#include "windows.h"

LoadManager::LoadManager() : AFileManager()
{
}

LoadManager::~LoadManager()
{
}

void LoadManager::openFile(const std::string &filename)
{
	this->_file.open(filename, std::ios::in | std::ios::binary);
}

void LoadManager::loadMap()
{
	unsigned int length = 0;

	// get length of file:
	this->_file.seekg(0, this->_file.end);
	length = this->_file.tellg();
	this->_file.seekg(0, this->_file.beg);

	while (length >= sizeof(SaveMapCase)) {
		SaveMapCase _case;

		this->_file.read((char *)(&_case), sizeof(SaveMapCase));
		length -= sizeof(SaveMapCase);
		
		this->_list.push_back(_case.convertToMapCase());
	}
}

std::list<MapCase *> *LoadManager::getList()
{
	return &(this->_list);
}