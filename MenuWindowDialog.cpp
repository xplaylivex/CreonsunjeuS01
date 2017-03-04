#include "MenuWindowDialog.hpp"

MenuWindowDialog::MenuWindowDialog(ACharacter *character_one, ACharacter *character_two, std::vector<std::string> &texts)
	: AWindow(
		FLAG_EVENT::CLICKABLE | FLAG_EVENT::INPUTABLE,
		sf::Vector2f(0, DataContainer::getInstance()->window.getSize().y - Tool::getHeightDialogWindow()),
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x, Tool::getHeightDialogWindow())
	),
	_texts(texts),
	_index(/*this->_texts.begin()*/0),
	_dialog_text(/**(this->_index)*/texts[0], Tool::getPositionDialogWindowText(), Tool::getSizeDialogWindowText()),
	_dialog_character_one(character_one->getPicture(), Tool::getPositionDialogWindowFirstImage(), Tool::getSizeDialogWindowImage()),
	_dialog_character_two(character_two->getPicture(), Tool::getPositionDialogWindowSecondImage(), Tool::getSizeDialogWindowImage())
{
	this->setClickHitbox(
		sf::Vector2f(0, DataContainer::getInstance()->window.getSize().y - Tool::getHeightDialogWindow()),
		sf::Vector2f(DataContainer::getInstance()->window.getSize().x, Tool::getHeightDialogWindow())
	);
	this->_view.setCenter(DataContainer::getInstance()->window.getView().getSize().x / 2, DataContainer::getInstance()->window.getView().getSize().y / 2);
	this->_view.setSize(DataContainer::getInstance()->window.getView().getSize());

	this->setCallback(FLAG_EVENT::CLICKABLE, [this](const sf::Event &event) -> bool {
		if (this->_nextText()) {
			this->_to_close = WINDOW_TO_DELETE;
		}
		return true;
	});
	this->setCallback(FLAG_EVENT::INPUTABLE, [this](const sf::Event &event) -> bool {
		if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Return) {
			if (this->_nextText()) {
				this->_to_close = WINDOW_TO_DELETE;
			}
			return true;
		}
		return false;
	});
}

MenuWindowDialog::~MenuWindowDialog()
{
	std::cout << "Destructeur menu window dialog" << std::endl;
}

void MenuWindowDialog::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::View tmp = target.getView();

	target.setView(this->_view);
	target.draw(this->_background);
	target.draw(this->_dialog_text);
	target.draw(this->_dialog_character_one);
	target.draw(this->_dialog_character_two);
	target.setView(tmp);
}

bool MenuWindowDialog::_nextText()
{
	if (this->_index != this->_texts.size()) {
		++this->_index;
		if (this->_index != this->_texts.size()) {
			this->_dialog_text.changeText(this->_texts[this->_index]);
		}
	}
	return (this->_index == this->_texts.size());
}
