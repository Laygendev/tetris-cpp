#pragma once

#ifndef DEF_GRID
#define DEF_GRID

#include <list>
#include <iterator>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>

#include "bloc.hpp"
#include "BlocMovable.hpp"
#include "ParticleSystem.hpp"

#include "Cell.hpp"

class Grid
{
public:
	Grid(StateGame *stateGame);
	~Grid();

	sf::Vector2f GetPositionByCell(int cellX, int cellY);

	void Update(sf::Clock& clock);
	void Draw(sf::RenderWindow& window);

	void AddBloc(Grid *grid, Bloc *bloc);
	bool checkHaveBloc(sf::Vector2i pos);
	bool CheckCollision(sf::Vector2i bodyCell);
	bool CheckCollisionLeft(sf::Vector2i bodyCell);
	bool CheckCollisionRight(sf::Vector2i bodyCell);
	void updateGrid(Bloc* bloc);
	bool gridIsFullY();
	void clearGrid();

	void playFx(sf::RenderWindow &window);
private:
	StateGame *m_stateGame;

	sf::SoundBuffer m_buffer;
	sf::Sound m_soundLineCompleted;
	std::vector<int> searchLineWithFullCell();
	void destroyLine(std::vector<int> completedLine);

	std::vector<Bloc> m_blocs;
	Cell *m_grid[9][19] = { NULL };

	sf::Vector2f m_offset;

	sf::Clock m_fxClock;
	bool m_playFx = false;
	std::vector<int> m_completedLineForFx;
	std::vector<sf::Texture*> m_completedLineTextureForFx;
	ParticleSystem m_particles;
};

#endif