#pragma once

#ifndef DEF_PARTICLESYSTEM
#define DEF_PARTICLESYSTEM

#include <SFML/Graphics.hpp>
#include <iostream>

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
	ParticleSystem(unsigned int count);

	void setEmitter(int index, sf::Vector2f position);
	void update(sf::Time elapsed);

	void setTexture(int index, sf::Texture *texture);

	bool isPlaying();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	struct Particle
	{
		sf::Vector2f velocity;
		sf::Time lifetime;
		sf::Texture *texture;
	};

	void resetParticle(std::size_t index);

	std::vector<Particle> m_particles;
	std::vector<sf::VertexArray> m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;

	bool m_startPlay = false;
};

#endif