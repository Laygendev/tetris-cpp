#include "App.hpp"

App::App()
	: m_renderWindow (sf::VideoMode(590, 960), "Tetris"),
	m_loader         (),
	m_background     (m_loader.GetBackground()),
	m_grid           (),
	m_bloc           (&m_grid, m_loader.GetBlocTexture(0), m_loader.GetBody(0)),
	m_clock          ()
{
	m_bloc.GetSprite().setPosition(m_grid.GetPositionByCell(0, 0));
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
		}

		m_bloc.Update(m_clock);
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
	m_bloc.Display(m_renderWindow);
	m_renderWindow.display();
}