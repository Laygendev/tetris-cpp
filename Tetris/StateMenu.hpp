#pragma once

#ifndef DEF_STATE_MENU
#define DEF_STATE_MENU

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "State.hpp"
#include "Button.hpp"
#include "ParticleSystem.hpp"

class App;

class StateMenu : public State
{
public:
	StateMenu(App *app);
	~StateMenu() = default;

	void run();
	void stop();

	void handleEvent(sf::Event event, sf::RenderWindow &renderWindow);
	void update();
	void draw(sf::RenderWindow &renderWindow);
private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;
	sf::Music m_music;

	sf::Font m_font;
	sf::Text m_textCredit;

	Button m_buttonStart;
	Button m_buttonCredit;
	Button m_buttonLeave;
	Button m_buttonBack;

	bool m_onCredit = false;
};

#endif