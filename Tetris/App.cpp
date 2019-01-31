#include "App.hpp"

App::App()
	: m_renderWindow (sf::VideoMode(590, 960), "Tetris")
	
{
	m_states.push_back(new StateMenu());
	m_states.push_back(new StateGame());
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
			
			m_states[m_currentState]->handleEvent(event);
		}

		m_states[m_currentState]->update();

		m_states[m_currentState]->draw(m_renderWindow);
	}


}

void App::pause()
{

}

void App::resume()
{

}
