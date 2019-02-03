#pragma once

#ifndef DEF_STATE
#define DEF_STATE

#include <SFML/Graphics.hpp>
#include <iostream>

class App;

class State
{
public:
	State(App *app);
	~State() = default;

	virtual void handleEvent(sf::Event event, sf::RenderWindow &renderWindow);
	virtual void update();
	virtual void draw(sf::RenderWindow &renderWindow);
	virtual void reset();
	virtual void run();
	virtual void stop();

protected:
	App* m_app;
};

#endif