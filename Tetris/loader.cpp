#include "Loader.hpp"

Loader::Loader()
{
	background.loadFromFile("ressources/Mockup/background.jpg");
	m_blocsTexture[0].loadFromFile("ressources/I/1.png");
	m_blocsTexture[1].loadFromFile("ressources/L/L.png");
	m_blocsTexture[2].loadFromFile("ressources/R/R.png");
	m_blocsTexture[3].loadFromFile("ressources/S/S.png");
	m_blocsTexture[4].loadFromFile("ressources/T/T_2.png");

	m_body[0][0].x = 0;
	m_body[0][0].y = 0;
	m_body[0][1].x = 0;
	m_body[0][1].y = 1;
	m_body[0][2].x = 0;
	m_body[0][2].y = 2;
	m_body[0][3].x = 0;
	m_body[0][3].y = 3;

	m_body[1][0].x = 0;
	m_body[1][0].y = 0;
	m_body[1][1].x = 0;
	m_body[1][1].y = 1;
	m_body[1][2].x = 0;
	m_body[1][2].y = 2;
	m_body[1][3].x = 1;
	m_body[1][3].y = 2;

	m_body[2][0].x = 0;
	m_body[2][0].y = 0;
	m_body[2][1].x = 0;
	m_body[2][1].y = 1;
	m_body[2][2].x = 1;
	m_body[2][2].y = 0;
	m_body[2][3].x = 1;
	m_body[2][3].y = 1;
}

sf::Texture* Loader::GetBackground()
{
	return &background;
}

sf::Texture* Loader::GetBlocTexture(int index)
{
	return &m_blocsTexture[index];
}

sf::Vector2i* Loader::GetBody(int index)
{
	return m_body[index];
}
