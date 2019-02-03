#include "StateCredit.hpp"

#include "App.hpp"

StateCredit::StateCredit(App *app)
	: State(app)
{
	m_music.openFromFile("ressources/sound/tetris-menu.ogg");
	m_music.play();
	m_music.setLoop(true);
	m_music.setVolume(10.f);
	m_backgroundTexture.loadFromFile("ressources/Mockup/menuBackground.png");
	m_background.setTexture(m_backgroundTexture);
}

void StateMenu::run()
{
	m_music.play();
}

void StateMenu::stop()
{
	m_music.stop();
}

void StateMenu::handleEvent(sf::Event event, sf::RenderWindow &renderWindow)
{
	m_buttonStart.handleEvent(event, renderWindow);

	if (m_buttonStart.isClicked(event))
	{
		m_app->setCurrentState(1);
	}
}

void StateMenu::update()
{

}

void StateMenu::draw(sf::RenderWindow &renderWindow)
{
	renderWindow.clear(sf::Color::Black);
	renderWindow.draw(m_background);
	m_buttonStart.draw(renderWindow);
	renderWindow.display();
}