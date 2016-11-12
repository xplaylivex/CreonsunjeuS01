#pragma once
#include "DataContainer.hpp"
#include "MapCase.hpp"

class DataContainer;
class MapCase;

struct SaveMapCase
{
	SaveMapCase();
	SaveMapCase(MapCase *);
	~SaveMapCase();

	MapCase *convertToMapCase();

	unsigned short			id;
	int						x;
	int						y;
	char					depth;
	bool					can_collide;
};