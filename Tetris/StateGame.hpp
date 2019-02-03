#pragma once

#ifndef DEF_STATE_GAME
#define DEF_STATE_GAME

#include <string>
#include <SFML/Audio.hpp>

#include "State.hpp"
#include "Loader.hpp"
#include "Background.hpp"
#include "Grid.hpp"
#include "BlocMovable.hpp"
#include "bloc.hpp"
#include "Cell.hpp"
#include "Button.hpp"

class App;

class StateGame : public State
{
public:
	StateGame(App *app);
	~StateGame() = default;

	void run();
	void stop();

	void handleEvent(sf::Event event, sf::RenderWindow &renderWindow);
	void update();
	void draw(sf::RenderWindow &renderWindow);

	Grid GetGrid();
	float getTimeBlocMovable();
	void decreaseTime();
	void reset();

	void addScore(int score);
private:
	Loader m_loader;
	Background m_background;
	Grid m_grid;
	sf::Music m_music;
	sf::Sound m_addBlocSound;
	sf::SoundBuffer m_buffer;

	BlocMovable *m_bloc;
	sf::Clock m_clock;
	float m_time_bloc_movable = 1.f;
	int m_number_bloc = 0;
	int m_next_bloc_rand = rand() % 5;

	sf::Sprite *m_next_bloc;
	sf::RectangleShape m_filter_loose;

	bool m_gameover = false;
	bool m_onPause = false;

	bool checkIfLoose();
	void nextBloc();

	Button *m_button[2];

	sf::Font m_font;
	sf::Text m_scoreText;
	sf::Text m_pauseText;
	sf::Text m_looseText;
	int m_score = 0;

};

#endif