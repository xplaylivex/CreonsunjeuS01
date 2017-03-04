#include "MenuWindowAlert.hpp"

MenuWindowAlert::MenuWindowAlert()
	: AWindow(
		FLAG_EVENT::INPUTABLE | FLAG_EVENT::CLICKABLE,
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x / 5, DataContainer::getInstance()->window.getSize().y / 5),
		sf::Vector2f(3 * DataContainer::getInstance()->window.getSize().x / 5, 3 * DataContainer::getInstance()->window.getSize().y / 5)
	),
	_is_displayed(false),
	_resume(
		std::string("Reprendre"),
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x / 3, 5 * DataContainer::getInstance()->window.getSize().y / 16),
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x / 3, DataContainer::getInstance()->window.getSize().x / 16)
	),
	_exit(
		std::string("Quitter"),
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x / 3, 5 * DataContainer::getInstance()->window.getSize().y / 16 + (2 * DataContainer::getInstance()->window.getSize().x / 16)),
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x / 3, DataContainer::getInstance()->window.getSize().x / 16)
	)
{
	this->_view.setCenter(DataContainer::getInstance()->window.getView().getSize().x / 2, DataContainer::getInstance()->window.getView().getSize().y / 2);
	this->_view.setSize(DataContainer::getInstance()->window.getView().getSize());

	this->setClickHitbox(
		sf::Vector2f(0.f, 0.f),
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x, DataContainer::getInstance()->window.getSize().y)
	);

	this->setCallback(FLAG_EVENT::CLICKABLE, [this](const sf::Event &event) -> bool {
		return this->_resume.click(event) || this->_exit.click(event);
	});

	this->setCallback(FLAG_EVENT::INPUTABLE, [this](const sf::Event &event) -> bool {
		if (event.key.code == sf::Keyboard::Escape) {
			this->_is_displayed = !this->_is_displayed;
			return true;
		}
		return false;
	});

	this->_resume.setClickHitbox(
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x / 3.f, 5.f * DataContainer::getInstance()->window.getSize().y / 16.f),
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x / 3.f, DataContainer::getInstance()->window.getSize().x / 16.f)
		);

	this->_exit.setClickHitbox(
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x / 3.f, 5.f * DataContainer::getInstance()->window.getSize().y / 16.f + (2.f * DataContainer::getInstance()->window.getSize().x / 16.f)),
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x / 3.f, DataContainer::getInstance()->window.getSize().x / 16.f)
	);

	this->_resume.setCallback(FLAG_EVENT::CLICKABLE, [this](const sf::Event &event) -> bool {
		this->_is_displayed = !this->_is_displayed;
		return true;
	});

	this->_exit.setCallback(FLAG_EVENT::CLICKABLE, [this](const sf::Event &event) -> bool {
		this->_do_close = true;
		return true;
	});
}

MenuWindowAlert::~MenuWindowAlert()
{
}

void MenuWindowAlert::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (this->_is_displayed) {
		sf::View tmp = target.getView();

		target.setView(this->_view);
		target.draw(this->_background);
		target.draw(this->_resume);
		target.draw(this->_exit);
		target.setView(tmp);
	}
}
