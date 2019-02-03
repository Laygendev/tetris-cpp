#include "StateMenu.hpp"

#include "App.hpp"

StateMenu::StateMenu(App *app)
	: State(app),
	m_buttonStart("Start", sf::Vector2f(182.f, 150.f)),
	m_buttonCredit("Credit", sf::Vector2f(182.f, 300.f)),
	m_buttonLeave("Exit", sf::Vector2f(182.f, 450.f)),
	m_buttonBack("Back", sf::Vector2f(182.f, 600.f))
{
	m_music.openFromFile("ressources/sound/tetris-menu.ogg");
	m_music.play();
	m_music.setLoop(true);
	m_music.setVolume(10.f);

	m_backgroundTexture.loadFromFile("ressources/Mockup/menuBackground.png");
	m_background.setTexture(m_backgroundTexture);

	m_font.loadFromFile("ressources/Font/telelower.ttf");
	m_textCredit.setFont(m_font);
	m_textCredit.setCharacterSize(20);
	m_textCredit.setString("Thanks to UnLucky Studio for assets:\nBackground, Bloc.\nThanks to create game assets for\nyellow steampunk ui displayed on button.\nThanks to Bogozi for the Tetris Theme music.\nThanks to khinsider for the Tetris Menu music.\nThanks to my girlfriend for supporting me\n on all my projects!");
	m_textCredit.setPosition(sf::Vector2f(60.f, 300.f));
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

	m_buttonCredit.handleEvent(event, renderWindow);

	if (m_buttonCredit.isClicked(event))
	{
		m_onCredit = true;
	}

	m_buttonBack.handleEvent(event, renderWindow);

	if (m_buttonBack.isClicked(event))
	{
		m_onCredit = false;
	}


	m_buttonLeave.handleEvent(event, renderWindow);

	if (m_buttonLeave.isClicked(event))
	{
		renderWindow.close();
	}
}

void StateMenu::update()
{
	
}

void StateMenu::draw(sf::RenderWindow &renderWindow)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(renderWindow);

	renderWindow.clear(sf::Color::Black);
	renderWindow.draw(m_background);

	if (!m_onCredit)
	{
		m_buttonStart.draw(renderWindow);
		m_buttonCredit.draw(renderWindow);
		m_buttonLeave.draw(renderWindow);
	}
	else
	{
		renderWindow.draw(m_textCredit);
		m_buttonBack.draw(renderWindow);
	}

	renderWindow.display();
}