#include "App.hpp"

App::App()
	: m_renderWindow (sf::VideoMode(590, 960), "Tetris")
	
{
	m_states.push_back(new StateMenu(this));
	m_states.push_back(new StateGame(this));
}

void App::run()
{

	while (m_renderWindow.isOpen())
	{
		sf::Event event;
		while (m_renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_renderWindow.close();
			
			m_states[m_currentState]->handleEvent(event, m_renderWindow);
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

void App::setCurrentState(int state)
{
	if (state == 1)
	{
		m_states[m_currentState]->reset();
	}

	m_states[m_currentState]->stop();

	m_currentState = state;

	m_states[m_currentState]->run();
}