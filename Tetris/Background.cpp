#include "Background.hpp"

Background::Background(sf::Texture *texture)
{
	sprite.setTexture(*texture);
}

void Background::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Background::SetTexture(sf::Texture *texture) {
	sprite.setTexture(*texture);
}