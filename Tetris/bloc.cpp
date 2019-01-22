#include "bloc.h"

Bloc::Bloc()
{
}

void Bloc::Display(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Bloc::SetTexture(sf::Texture *texture) {
	std::cout << "Set texture" << std::endl;
	sprite.setTexture(*texture);
}

sf::Sprite Bloc::GetSprite() {
	return sprite;
}