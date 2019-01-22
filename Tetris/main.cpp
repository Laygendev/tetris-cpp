#include <SFML/Graphics.hpp>

#include "loader.h"
#include "bloc.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(590, 960), "SFML works!");

	Loader loader = Loader();
	Bloc bloc = Bloc();

	bloc.SetTexture(loader.GetBackground());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(bloc.GetSprite());
		window.display();
	}

	return 0;
}