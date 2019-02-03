#include "BlocMovable.hpp"
#include "Grid.hpp"
#include "StateGame.hpp"

BlocMovable::BlocMovable(StateGame *stateGame, Grid* grid, sf::Texture *texture, const std::vector <Cell*> cells) : Bloc(stateGame, grid, texture, cells)
{
	for (int i = 0; i < m_cells.size(); ++i)
	{
		m_effects[i].setSize(sf::Vector2f(44.f, 44.f));

		std::string tmp_color = m_cells[i]->getColor();
		
		sf::Color rectColor;
		if (tmp_color == "yellow") {
			rectColor = sf::Color(240, 168, 48, 50);
		}
		else if (tmp_color == "white") {
			rectColor = sf::Color(252, 235, 182, 50);
		}
		else if (tmp_color == "marron") {
			rectColor = sf::Color(94, 65, 47, 50);
		}
		else if (tmp_color == "orange") {
			rectColor = sf::Color(240, 120, 24, 50);
		}
		else if (tmp_color == "green") {
			rectColor = sf::Color(120, 192, 168, 50);
		}
		else if (tmp_color == "rose") {
			rectColor = sf::Color(230, 34, 169, 50);
		}

		m_effects[i].setFillColor(rectColor);
	}
}

BlocMovable::~BlocMovable()
{
}

void BlocMovable::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
	{
		m_onSpeedEffect = false;
	}

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			bool canGoLeft = true;

			for (int i = 0; i < m_cells.size(); ++i)
			{
				if (m_cells[i]->getPos().x - 1 < 0) {
					canGoLeft = false;
					break;
				}

				if (CheckColliderLeft(m_cells[i]->getPos())) {
					canGoLeft = false;
					break;
				}
			}

			if (canGoLeft) {
				m_cell_pos.x -= 1;
				for (int i = 0; i < m_cells.size(); ++i)
				{
					m_cells[i]->increasePos(-1, 0);
				}
			}
		}
		else if (event.key.code == sf::Keyboard::Right)
		{
			bool canGoRight = true;

			for (int i = 0; i < m_cells.size(); ++i)
			{
				if (m_cells[i]->getPos().x + 1 > 8) {
					canGoRight = false;
					break;
				}

				if (CheckColliderRight(m_cells[i]->getPos())) {
					canGoRight = false;
					break;
				}
			}
			if (canGoRight) {
				m_cell_pos.x += 1;
				for (int i = 0; i < m_cells.size(); ++i)
				{
					m_cells[i]->increasePos(1, 0);
				}
			}
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			m_onSpeedEffect = true;
		}
		else if (event.key.code == sf::Keyboard::Up)
		{
			int lastCellX = NULL;
			bool outLeft = false;
			bool outRight = false;
			bool outBottom = false;

			bool canRotate = false;

			// Change cell direction
			for (int i = 0; i < m_cells.size(); ++i)
			{
				sf::Vector2i pos = m_cells[i]->simulateNextRotation();

				if (pos.x < 0) {
					outLeft = true;
				}

				if (pos.x + 1 > 9) {
					outRight = true;
				}

				if (pos.y + 1 > 19) {
					outBottom = true;
				}

				// Testes si y'a un bloc dans les nouvelles coordonnées ou si on sort dans l'écran en bas
				if (m_grid->checkHaveBloc(pos))
				{
					canRotate = true;
				}

			}

			if (!outLeft && !outRight && !outBottom && !canRotate)
			{
				for (int i = 0; i < m_cells.size(); ++i)
				{
					m_cells[i]->nextRotation();
				}
			}
		}
	}
}

void BlocMovable::Update(sf::Clock &clock)
{
	sf::Time elapsed = clock.getElapsedTime();

	if (m_onSpeedEffect)
	{
		sf::Time elapsedSpeedEffect = clock.getElapsedTime();

		if (elapsedSpeedEffect.asMilliseconds() >= 20)
		{
			m_stateGame->addScore(1);
			clock.restart();
			bool canGoDown = true;

			if (CheckCollider()) {
				canGoDown = false;
			}

			if (canGoDown) {
				m_cell_pos.y += 1;
				for (int i = 0; i < m_cells.size(); ++i)
				{
					m_cells[i]->increasePos(0, 1);
				}
			}
		}
	}

	if (elapsed.asSeconds() > m_stateGame->getTimeBlocMovable() && !m_hasCollision) {
		clock.restart();

		if (CheckCollider()) {

		}
		else {
			m_cell_pos.y += 1;

			for (int i = 0; i < m_cells.size(); ++i)
			{
				m_cells[i]->increasePos(0, 1);
			}
		}
	}

	for (int i = 0; i < m_cells.size(); ++i)
	{
		m_cells[i]->update(m_grid);
	}

}

bool BlocMovable::CheckCollider()
{
	for (int i = 0; i < m_cells.size(); ++i)
	{
		if (m_grid->CheckCollision(m_cells[i]->getPos())) {
			m_hasCollision = true;
			return true;
		}

		if ((m_cells[i]->getPos().y + 1) > 18) {
			m_hasCollision = true;
			return true;
		}
	}

	return false;
}

bool BlocMovable::CheckColliderLeft(sf::Vector2i cell)
{
	if (m_grid->CheckCollisionLeft(cell)) {
		return true;
	}

	return false;
}

bool BlocMovable::CheckColliderRight(sf::Vector2i cell)
{
	if (m_grid->CheckCollisionRight(cell)) {
		return true;
	}

	return false;
}

bool BlocMovable::GetHasCollision()
{
	return m_hasCollision;
}
