#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "DataContainer.hpp"
#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "KeyboardManager.hpp"
#include "Tool.hpp"

class CoreController
{
public:
	CoreController();
	~CoreController();
	void process();
};

