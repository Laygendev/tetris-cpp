#include "StateGame.hpp"
#include "App.hpp"

StateGame::StateGame(App *app)
	: State(app),
	m_loader(),
	m_background(m_loader.GetBackground()),
	m_grid(this),
	m_clock(),
	m_filter_loose(sf::Vector2f(400.f, 844.f))
{
	m_font.loadFromFile("ressources/Font/telelower.ttf");

	m_scoreText.setFont(m_font);
	m_scoreText.setPosition(sf::Vector2f(532.f, 101.f));
	m_scoreText.setFillColor(sf::Color(254.f, 237.f, 183.f, 255.f));
	m_scoreText.setCharacterSize(18);
	m_scoreText.setString("0");

	m_pauseText.setFont(m_font);
	m_pauseText.setPosition(sf::Vector2f(200.f, 200.f));
	m_pauseText.setString("Pause");

	m_looseText.setFont(m_font);
	m_looseText.setPosition(sf::Vector2f(160.f, 200.f));
	m_looseText.setString("Game Over");

	m_music.openFromFile("ressources/sound/tetris-game.ogg");
	m_music.setLoop(true);
	m_music.setVolume(10.f);

	m_buffer.loadFromFile("ressources/sound/pose.wav");
	m_addBlocSound.setBuffer(m_buffer);

	m_button[0] = new Button("Replay", sf::Vector2f(120.f, 350.f));
	m_button[1] = new Button("Menu", sf::Vector2f(120.f, 500.f));

	m_filter_loose.setPosition(sf::Vector2f(18.f, 95.f));
	m_filter_loose.setFillColor(sf::Color(0, 0, 0, 150));
	nextBloc();
}

void StateGame::run()
{
	m_music.play();
}

void StateGame::stop()
{
	m_music.stop();
}


void StateGame::handleEvent(sf::Event event, sf::RenderWindow &renderWindow)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && !m_gameover)
	{
		m_onPause = !m_onPause;
	}

	if (!m_onPause)
	{
		if (m_bloc != NULL)
		{
			m_bloc->handleEvent(event);
		}
	}

	if (m_gameover || m_onPause)
	{
		m_button[0]->handleEvent(event, renderWindow);
		m_button[1]->handleEvent(event, renderWindow);

		if (m_button[0]->isClicked(event))
		{
			m_app->setCurrentState(1);
		}

		if (m_button[1]->isClicked(event))
		{
			reset();
			m_app->setCurrentState(0);
		}

	}
}

void StateGame::update()
{
	if (!m_onPause)
	{
		m_grid.Update(m_clock);

		if (m_bloc != NULL)
		{

			m_bloc->Update(m_clock);

			if (m_bloc->GetHasCollision())
			{
				m_addBlocSound.play();
				m_grid.AddBloc(&m_grid, m_bloc);
				delete m_bloc;
				m_bloc = 0;

				if (!checkIfLoose()) {
					nextBloc();
				}
			}
		}
	}
	else
	{

	}
}

void StateGame::decreaseTime()
{
	if (m_number_bloc % 10 == 0)
	{
		m_time_bloc_movable -= 0.1f;

		if (m_time_bloc_movable <= 0.2f)
		{
			m_time_bloc_movable = 0.2f;
		}
	}
}

float StateGame::getTimeBlocMovable()
{
	return m_time_bloc_movable;
}

Grid StateGame::GetGrid()
{
	return m_grid;
}

void StateGame::draw(sf::RenderWindow &renderWindow)
{
	renderWindow.clear(sf::Color::Black);
	m_background.draw(renderWindow);
	renderWindow.draw(m_scoreText);
	m_grid.Draw(renderWindow);
	if (m_bloc != NULL)
	{
		m_bloc->Display(renderWindow);
	}

	if (m_next_bloc != NULL)
	{
		renderWindow.draw(*m_next_bloc);
	}

	if (m_onPause)
	{
		renderWindow.draw(m_filter_loose);
		renderWindow.draw(m_pauseText);
		m_button[0]->draw(renderWindow);
		m_button[1]->draw(renderWindow);
	}

	if (m_gameover)
	{
		renderWindow.draw(m_filter_loose);
		renderWindow.draw(m_looseText);
		m_button[0]->draw(renderWindow);
		m_button[1]->draw(renderWindow);
	}

	renderWindow.display();
}

bool StateGame::checkIfLoose()
{
	if (m_grid.gridIsFullY())
	{
		m_gameover = true;
		return true;
	}

	return false;
}

void StateGame::nextBloc()
{
	m_number_bloc++;
	decreaseTime();

	m_bloc = new BlocMovable(this, &m_grid, m_loader.GetBlocTexture(m_next_bloc_rand), m_loader.GetCell(m_next_bloc_rand));

	m_next_bloc_rand = rand() % 6;
	m_next_bloc = new sf::Sprite();
	m_next_bloc->setTexture(*m_loader.GetBlocSpriteTexture(m_next_bloc_rand));
	if (m_next_bloc->getTextureRect().height > 120)
	{
		m_next_bloc->setScale(0.6f, 0.6f);
		m_next_bloc->setOrigin(sf::Vector2f(m_next_bloc->getTextureRect().width / 2, m_next_bloc->getTextureRect().height / 2));
		m_next_bloc->setPosition(sf::Vector2f(505.f, 235.f));
	}
	else
	{
		m_next_bloc->setScale(0.8f, 0.8f);
		m_next_bloc->setOrigin(sf::Vector2f(m_next_bloc->getTextureRect().width / 2, m_next_bloc->getTextureRect().height / 2));
		m_next_bloc->setPosition(sf::Vector2f(505.f, 235.f));
	}
}

void StateGame::reset()
{
	m_gameover = false;
	m_onPause = false;
	m_time_bloc_movable = 1.f;
	m_number_bloc = 0;

	m_score = 0;
	m_scoreText.setString("0");

	m_grid.clearGrid();

	nextBloc();
}

void StateGame::addScore(int score)
{
	m_score += score;
	m_scoreText.setString(std::to_string(m_score));
}