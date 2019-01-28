#include "Test.hpp"

Test::Test() {
	pos.push_back(sf::Vector2i(0, 0));
	pos.push_back(sf::Vector2i(0, 1));
	pos.push_back(sf::Vector2i(0, 2));
	pos.push_back(sf::Vector2i(0, 3));
	pos.push_back(sf::Vector2i(0, 4));

	std::cout << pos.size() << std::endl;
}

void Test::deleteVector() {
	pos.erase(pos.begin() + 2);
}

std::vector<sf::Vector2i> Test::getPos()
{
	return pos;
}