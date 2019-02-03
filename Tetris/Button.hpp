#pragma once

#ifndef DEF_BUTTON
#define DEF_BUTTON

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Button
{
public:
	Button(std::string text, sf::Vector2f pos);
	~Button() = default;

	void handleEvent(sf::Event event, sf::RenderWindow &renderWindow);
	bool isClicked(sf::Event event);
	void draw(sf::RenderWindow &renderWindow);

private:
	sf::Texture m_texture[3];
	sf::Sprite m_sprite;

	sf::Font m_font;
	sf::Text m_text;

	sf::Vector2f m_pos;

	bool m_onHover = false;
};

#endif