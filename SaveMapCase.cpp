#include "SaveMapCase.hpp"

SaveMapCase::SaveMapCase()
{
}

SaveMapCase::SaveMapCase(MapCase *_case)
{
	this->id = _case->id;
	this->x = _case->humanCoord.x;
	this->y = _case->humanCoord.y;
	this->depth = _case->depth;
	this->can_collide = _case->can_collide;
}


SaveMapCase::~SaveMapCase()
{
}

MapCase * SaveMapCase::convertToMapCase()
{
	std::vector<sf::Texture *> &texture = DataContainer::getInstance()->texture_manager.getSetTexture();

	if (texture.size() == 0) {
		return NULL;
	}

	return new MapCase(this, *(texture[rand() % texture.size()]));
}
