#include "StateGame.hpp"

StateGame::StateGame()
	: State(),
	m_loader(),
	m_background(m_loader.GetBackground()),
	m_grid(),
	m_clock(),
	m_filter_loose(sf::Vector2f(400.f, 844.f))
{
	m_filter_loose.setPosition(sf::Vector2f(18.f, 95.f));
	m_filter_loose.setFillColor(sf::Color(0, 0, 0, 150));
	nextBloc();
}

void StateGame::handleEvent(sf::Event event)
{
	if (m_bloc != NULL && event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			m_bloc->translate("left");
		}
		else if (event.key.code == sf::Keyboard::Right)
		{
			m_bloc->translate("right");
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			m_bloc->translate("down");
		}
		else if (event.key.code == sf::Keyboard::Up)
		{
			m_bloc->translate("up");
		}
	}
}

void StateGame::update()
{
	m_grid.Update(m_clock);

	if (m_bloc != NULL)
	{

		m_bloc->Update(m_clock);

		if (m_bloc->GetHasCollision())
		{
			m_grid.AddBloc(&m_grid, m_bloc);
			delete m_bloc;
			m_bloc = 0;

			if (!checkIfLoose()) {
				nextBloc();
			}
		}
	}
}

void StateGame::decreaseTime()
{
	if (m_number_bloc % 2 == 0)
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
	m_grid.Draw(renderWindow);
	if (m_bloc != NULL)
	{
		m_bloc->Display(renderWindow);
	}

	if (m_next_bloc != NULL)
	{
		renderWindow.draw(*m_next_bloc);
	}

	if (m_gameover)
	{
		renderWindow.draw(m_filter_loose);
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

	m_next_bloc_rand = rand() % 5;
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