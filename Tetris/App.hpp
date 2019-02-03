#pragma once

#ifndef DEF_APP
#define DEF_APP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "State.hpp"
#include "StateMenu.hpp"
#include "StateGame.hpp"

class App final
{
public:
	App();
	~App() = default;

	void run();
	void pause();
	void resume();

	void setCurrentState(int state);
private:
	sf::RenderWindow m_renderWindow;

	std::vector<State*> m_states;

	int m_currentState = 0;
};

#endif