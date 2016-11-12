#include "SaveManager.hpp"

SaveManager::SaveManager() : AFileManager()
{
}


SaveManager::~SaveManager()
{
}

void SaveManager::openFile(const std::string &filename)
{
	_file.open(filename, std::ios::out | std::ios::trunc | std::ios::binary);
}

void SaveManager::saveMap(const IsometricMap *map)
{
	std::list<MapCase *> list = map->getCaseList();

	for (std::list<MapCase *>::iterator _case = list.begin(); _case != list.end(); ++_case) {
		SaveMapCase tmp_case((*_case));

		this->_file.write((char *)(&tmp_case), sizeof(tmp_case));
	}
}
