#pragma once

#ifndef DEF_APP
#define DEF_APP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Loader.hpp"
#include "Background.hpp"
#include "Grid.hpp"
#include "BlocMovable.hpp"
#include "bloc.hpp"
#include "Cell.hpp"

class App final
{
public:
	App();
	~App() = default;

	void run();
	void pause();
	void resume();
	void decreaseTime();

	Grid GetGrid();
	float getTimeBlocMovable();

private:
	sf::RenderWindow m_renderWindow;
	Loader m_loader;
	Background m_background;
	Grid m_grid;
	BlocMovable *m_bloc;
	sf::Clock m_clock;
	float m_time_bloc_movable = 0.8f;
	int m_number_bloc = 0;
	int m_next_bloc_rand = rand() % 5;

	sf::Sprite *m_next_bloc;

	void draw();
	void nextBloc();
};

#endif