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

class App final
{
public:
	App();
	~App() = default;

	void run();
	void pause();
	void resume();

	Grid GetGrid();

private:
	sf::RenderWindow m_renderWindow;
	Loader m_loader;
	Background m_background;
	Grid m_grid;
	BlocMovable *m_bloc;
	sf::Clock m_clock;

	void draw();
	void nextBloc();
};

#endif