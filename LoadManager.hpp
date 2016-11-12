#pragma once
#include <iostream>
#include <fstream>
#include "AFileManager.hpp"
#include "DataContainer.hpp"
#include "MapCase.hpp"
#include "SaveMapCase.hpp"

class DataContainer;

class LoadManager : public AFileManager
{
public:
	LoadManager();
	~LoadManager();

	virtual void	openFile(const std::string &);
	void			loadMap();

	std::list<MapCase*> *getList();

private:
	std::list<MapCase *>	_list;
};

