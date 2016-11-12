#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "ACharacter.hpp"
#include "DataContainer.hpp"
#include "Enum.hpp"
#include "MapCase.hpp"
#include "Tool.hpp"

class ACharacter;
class DataContainer;
class MapCase;

class CharacterSprite : public ACharacter
{
public:
	CharacterSprite();
	~CharacterSprite();

	void			changeOrientation(const std::list<KeyConstants> &);
};