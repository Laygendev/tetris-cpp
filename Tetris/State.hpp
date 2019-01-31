#pragma once

#ifndef DEF_STATE
#define DEF_STATE

#include <SFML/Graphics.hpp>
#include <iostream>

class State
{
public:
	State();
	~State() = default;

	virtual void handleEvent(sf::Event event);
	virtual void update();
	virtual void draw(sf::RenderWindow &renderWindow);
};

#endif