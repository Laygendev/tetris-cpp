#include "StateMenu.hpp"

StateMenu::StateMenu()
	: State()
{
}

void StateMenu::handleEvent(sf::Event event)
{

}

void StateMenu::update()
{
	
}

void StateMenu::draw(sf::RenderWindow &renderWindow)
{
	renderWindow.clear(sf::Color::Black);
	renderWindow.display();
}