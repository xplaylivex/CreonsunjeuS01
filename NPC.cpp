#include "NPC.hpp"
#include "MapCase.hpp"

NPC::NPC() : ACharacter()
{
	MapCase *random_case = DataContainer::getInstance()->map->getRandomCase();
	float x_float = (float)(rand() % 100) / 100;
	float y_float = (float)(rand() % 100) / 100;

	this->_position = sf::Vector2f(random_case->humanCoord.x + x_float, random_case->humanCoord.y + y_float);

	this->move(this->_position);
	this->_currentCase = random_case;
	if (random_case) {
		random_case->addObject(this);
	}
}

NPC::~NPC()
{
}
