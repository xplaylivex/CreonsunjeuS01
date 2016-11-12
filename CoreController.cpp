#include "CoreController.hpp"

CoreController::CoreController()
{
}

CoreController::~CoreController()
{
}

void CoreController::process()
{
	sf::Clock		clock;
	DataContainer	*data = DataContainer::getInstance();

	srand(time(NULL));

	data->texture_manager.loadSet("set_one");

	data->load_manager->openFile("mymap");
	data->load_manager->loadMap();
	data->load_manager->closeFile();

	data->init(data->load_manager->getList());

	while (data->window.isOpen())
	{
		sf::Event event;

		data->clock.update(clock);
		while (data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				data->window.close();
			}

			data->keyboard->eventStorage(event);
		}

		data->update();
		data->draw();
	}
}