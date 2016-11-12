#include "IsometricMap.hpp"
#include <iostream>

IsometricMap::IsometricMap(std::list<MapCase *> *list)
	: _shadow_tile(sf::Quads, 4), _container(*list)
{
	for (std::list<MapCase *>::iterator initial_case = list->begin(); initial_case != list->end(); ++initial_case) {

		if ((*initial_case)->isFullyLinked()) {
			initial_case = list->erase(initial_case);
		}

		for (std::list<MapCase *>::iterator comp_case = list->begin(); comp_case != list->end(); ++comp_case) {
			if ((*initial_case)->id == (*comp_case)->id) {
				continue;
			}

			MapCase::linkCases((*initial_case), (*comp_case));

			if ((*comp_case)->isFullyLinked()) {
				comp_case = list->erase(comp_case);
				--comp_case;
			}
			if ((*initial_case)->isFullyLinked()) {
				initial_case = list->erase(initial_case);
				--initial_case;
				break;
			}
		}
	}
}

IsometricMap::~IsometricMap()
{
	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		delete (*it);
	}
}

void IsometricMap::renderMap(sf::RenderWindow &window, const GlobalLight &light)
{
	bool already_displayed_main_character = false;

	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if (Tool::isInBoundDataCoord((*it)->humanCoord, DataContainer::getInstance()->getMinCoordBound(), DataContainer::getInstance()->getMaxCoordBound())) {
			(*it)->update();

			window.draw((**it));

			(*it)->sortObjects();
			for (std::list<IObject *>::iterator obj = (*it)->getListCharacterOn().begin(); obj != (*it)->getListCharacterOn().end(); ++obj) {
				DataContainer::getInstance()->window.draw(**obj);
			}
			(*it)->removeMainCharacter();
		}
	}
}

MapCase *IsometricMap::findTile(const sf::Vector2f &position)
{
	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if (floor((*it)->coord.x) == floor(position.x) && floor((*it)->coord.y) == floor(position.y)) {
			return *it;
		}
	}

	return NULL;
}

MapCase * IsometricMap::findHumanTile(const sf::Vector2i &position)
{
	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if ((*it)->humanCoord.x == position.x && (*it)->humanCoord.y == position.y) {
			return *it;
		}
	}

	return NULL;
}

sf::VertexArray & IsometricMap::getShadowTile()
{
	return this->_shadow_tile;
}

std::list<MapCase*> IsometricMap::getCaseList() const
{
	return this->_container;
}

MapCase * IsometricMap::getRandomCase() const
{
	unsigned int random_number = rand() % this->_container.size();
	unsigned int i = 0;

	for (std::list<MapCase *>::const_iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if (i == random_number) {
			return *it;
		}
		++i;
	}

	return nullptr;
}
