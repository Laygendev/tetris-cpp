#include "State.hpp"

State::State(App *app) {
	m_app = app;
}

void State::handleEvent(sf::Event event, sf::RenderWindow &renderWindow) {}

void State::update() {}

void State::draw(sf::RenderWindow &renderWindow) {}

void State::reset() {}

void State::run() {}

void State::stop() {}