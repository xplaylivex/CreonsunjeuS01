#pragma once
#include <iostream>
#include <fstream>
#include "IsometricMap.hpp"
#include "MapCase.hpp"
#include "SaveMapCase.hpp"
#include "AFileManager.hpp"

class IsometricMap;

class SaveManager : public AFileManager
{
public:
	SaveManager();
	~SaveManager();

	virtual void	openFile(const std::string &);
	void			saveMap(const IsometricMap *);
};