#pragma once

#include <list>
#include <SFML/Graphics.hpp>
#include "MapCase.hpp"
#include "GlobalLight.hpp"
#include "Item.hpp"
#include "Tool.hpp"
#include "DataContainer.hpp"

class MapCase;
class DataContainer;

class IsometricMap
{
public:
	IsometricMap(std::list<MapCase *> *);
	~IsometricMap();

	void					renderMap(sf::RenderWindow &, const GlobalLight &);
	MapCase					*findTile(const sf::Vector2f &);
	MapCase					*findHumanTile(const sf::Vector2i &);

	sf::VertexArray			&getShadowTile();
	std::list<MapCase *>	getCaseList() const;
	MapCase					*getRandomCase() const;

private:
	std::list<MapCase *>	_container;
	sf::VertexArray			_shadow_tile;
};