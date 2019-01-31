#pragma once

#ifndef DEF_STATE_GAME
#define DEF_STATE_GAME

#include "State.hpp"
#include "Loader.hpp"
#include "Background.hpp"
#include "Grid.hpp"
#include "BlocMovable.hpp"
#include "bloc.hpp"
#include "Cell.hpp"

class StateGame : public State
{
public:
	StateGame();
	~StateGame() = default;

	void handleEvent(sf::Event event);
	void update();
	void draw(sf::RenderWindow &renderWindow);

	Grid GetGrid();
	float getTimeBlocMovable();
	void decreaseTime();
private:
	Loader m_loader;
	Background m_background;
	Grid m_grid;
	BlocMovable *m_bloc;
	sf::Clock m_clock;
	float m_time_bloc_movable = 1.f;
	int m_number_bloc = 0;
	int m_next_bloc_rand = rand() % 5;

	sf::Sprite *m_next_bloc;
	sf::RectangleShape m_filter_loose;

	bool m_gameover = false;

	bool checkIfLoose();
	void nextBloc();
};

#endif