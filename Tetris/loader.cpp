#include "Loader.hpp"

Loader::Loader()
{
	background.loadFromFile("ressources/Mockup/background.jpg");
	m_blocsTexture[0].loadFromFile("ressources/I/1.png");
	m_blocsTexture[1].loadFromFile("ressources/L/L.png");
	m_blocsTexture[2].loadFromFile("ressources/R/R.png");
	m_blocsTexture[3].loadFromFile("ressources/S/S.png");
	m_blocsTexture[4].loadFromFile("ressources/T/T_2.png");
}

sf::Texture* Loader::GetBackground()
{
	return &background;
}

sf::Texture* Loader::GetBlocTexture(int index)
{
	return &m_blocsTexture[index];
}
