#include "CoreController.hpp"
#include "MenuWindowAlert.hpp"
#include "MenuWindowDialog.hpp"

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

	/* test */
	srand(time(NULL));

	data->texture_manager.loadSet("set_one");

	data->load_manager->openFile("mymap");
	data->load_manager->loadMap();
	data->load_manager->closeFile();

	data->init(data->load_manager->getList());


	/* test */


	std::vector<std::string> tutu;
	tutu.push_back("Ceci est un test");
	tutu.push_back("Ceci marche");
	tutu.push_back("Ca va disparaitre");

	//MenuWindowDialog	*toto	= new MenuWindowDialog(data->npcs.front(), data->main_character, tutu);
	MenuWindowAlert		*alert	= new MenuWindowAlert();

	//this->menu_manager._menu_elements.push_back(toto);
	this->menu_manager._menu_elements.push_back(alert);

	/* test */

	while (data->window.isOpen())
	{
		sf::Event event;

		data->clock.update(clock);
		this->input_store.cleanScroll();
		this->menu_manager.resetWindows();
		while (data->window.pollEvent(event))
		{
			if (!this->input_store.addEvent(event)) {
				data->window.close();
				return;
			}
		}

		data->keyboard->eventStorage(this->input_store.getKeyEventsForKeyboard());
		if (this->menu_manager.processEvents(this->input_store)) {
			data->window.close();
			return;
		}
		this->menu_manager.clearWindows();

		data->update();
		data->draw();
		this->menu_manager.draw();
		data->window.display();
	}
}