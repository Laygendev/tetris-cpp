#include "Button.hpp"

Button::Button(std::string text, sf::Vector2f pos)
{
	m_pos = pos;

	m_texture[0].loadFromFile("ressources/button.png");
	m_texture[1].loadFromFile("ressources/buttonHover.png");
	m_texture[2].loadFromFile("ressources/buttonClic.png");

	m_sprite.setTexture(m_texture[0]);
	m_sprite.setPosition(pos);

	m_font.loadFromFile("ressources/Font/telelower.ttf");

	m_text.setFont(m_font);
	m_text.setString(text);
	m_text.setOrigin(sf::Vector2f(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2));
	m_text.setPosition(sf::Vector2f(m_pos.x + m_sprite.getTextureRect().width / 2, m_pos.y - m_text.getGlobalBounds().height / 2 + m_sprite.getTextureRect().height / 2));
}

void Button::handleEvent(sf::Event event, sf::RenderWindow &renderWindow)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(renderWindow);

	if (mousePosition.x >= m_pos.x && mousePosition.x <= m_pos.x + m_sprite.getTextureRect().width
		&& mousePosition.y >= m_pos.y && mousePosition.y <= m_pos.y + m_sprite.getTextureRect().height)
	{
		m_onHover = true;
		m_sprite.setTexture(m_texture[1]);
	}
	else
	{
		m_onHover = false;
		m_sprite.setTexture(m_texture[0]);
	}
}

bool Button::isClicked(sf::Event event)
{
	if (m_onHover && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_sprite.setTexture(m_texture[2]);
		return true;
	}

	return false;
}


void Button::draw(sf::RenderWindow &renderWindow)
{
	renderWindow.draw(m_sprite);
	renderWindow.draw(m_text);
}