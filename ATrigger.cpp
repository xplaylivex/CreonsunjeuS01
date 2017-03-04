#include "ATrigger.hpp"

ATrigger::ATrigger() : _callback([](const sf::Event &event) -> bool { return true; })
{
}

ATrigger::~ATrigger()
{
}

void ATrigger::setCallback(const std::function<bool(const sf::Event&)> &callback)
{
	this->_callback = callback;
}
