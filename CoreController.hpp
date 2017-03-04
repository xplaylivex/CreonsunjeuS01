#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "DataContainer.hpp"
#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "KeyboardManager.hpp"
#include "MenuManager.hpp"
#include "InputStorage.hpp"
#include "Tool.hpp"

class CoreController
{
public:
	CoreController();
	~CoreController();
	void process();

private:
	MenuManager		menu_manager;
	InputStorage	input_store;
};

