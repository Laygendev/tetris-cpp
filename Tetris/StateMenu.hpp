#pragma once

#ifndef DEF_STATE_MENU
#define DEF_STATE_MENU

#include <SFML/Graphics.hpp>

#include "State.hpp"

class StateMenu : public State
{
public:
	StateMenu();
	~StateMenu() = default;

	void handleEvent(sf::Event event);
	void update();
	void draw(sf::RenderWindow &renderWindow);
private:
};

#endif