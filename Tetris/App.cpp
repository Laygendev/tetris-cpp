#include "App.hpp"

App::App()
	: m_renderWindow (sf::VideoMode(590, 960), "Tetris"),
	m_loader         (),
	m_background     (m_loader.GetBackground()),
	m_grid           (),
	m_clock          ()
{
	m_bloc = new BlocMovable(&m_grid, m_loader.GetBlocTexture(0), m_loader.GetCell(0)),
	m_bloc->GetSprite().setPosition(m_grid.GetPositionByCell(0, 0));
}

void App::run()
{
	m_renderWindow.setMouseCursorVisible(false);

	while (m_renderWindow.isOpen())
	{
		sf::Event event;
		while (m_renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_renderWindow.close();

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
			}
		}

		if (m_bloc != NULL)
		{
			m_bloc->Update(m_clock);

			if (m_bloc->GetHasCollision())
			{
				m_grid.AddBloc(m_bloc);
				nextBloc();
			}
		}

		draw();
	}
}

void App::pause()
{

}

void App::resume()
{

}

Grid App::GetGrid()
{
	return m_grid;
}

void App::draw()
{
	m_renderWindow.clear(sf::Color::Black);
	m_background.draw(m_renderWindow);
	m_grid.Draw(m_renderWindow);
	if (m_bloc != NULL)
	{
		m_bloc->Display(m_renderWindow);
	}
	m_renderWindow.display();
}

void App::nextBloc()
{
	int random_bloc = rand() % 1;
	delete m_bloc;
	m_bloc = new BlocMovable(&m_grid, m_loader.GetBlocTexture(random_bloc), m_loader.GetCell(random_bloc)),
	m_bloc->GetSprite().setPosition(m_grid.GetPositionByCell(0, 0));
}