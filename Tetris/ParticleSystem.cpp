#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(unsigned int count) :
	m_particles(count),
	m_lifetime(sf::seconds(2)),
	m_emitter(0.f, 0.f)
{
	for (int i = 0; i < count; i++)
	{
		m_vertices.push_back(sf::VertexArray(sf::Quads, 4));
	}

	for (std::size_t i = 0; i < m_particles.size(); ++i) {
		m_vertices[i][0].texCoords = sf::Vector2f(0, 0);
		m_vertices[i][1].texCoords = sf::Vector2f(44.f, 0);
		m_vertices[i][2].texCoords = sf::Vector2f(44.f, 44.f);
		m_vertices[i][3].texCoords = sf::Vector2f(0, 44.f);
	}

}

void ParticleSystem::setEmitter(int index, sf::Vector2f position)
{
	m_vertices[index][0].position = position;
	m_vertices[index][1].position = position + sf::Vector2f(0, 44.f);
	m_vertices[index][2].position = position + sf::Vector2f(44.f, 44.f);
	m_vertices[index][3].position = position + sf::Vector2f(44.f, 0);

	float angle = (std::rand() % 360) * 3.14f / 180.f;
	float speed = (1000 - 500) * ((double)rand() / (double)RAND_MAX) + 500;
	m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	m_particles[index].lifetime = sf::milliseconds(2000);

	m_startPlay = true;
}

void ParticleSystem::setTexture(int index, sf::Texture *texture)
{
	m_particles[index].texture = texture;
}

void ParticleSystem::update(sf::Time elapsed)
{
	for (std::size_t i = 0; i < m_particles.size(); ++i)
	{
		Particle& p = m_particles[i];
		p.lifetime -= elapsed;

		p.velocity.y += 1.f;

		if (p.lifetime <= sf::Time::Zero) {
			resetParticle(i);
		}
		else {
			m_vertices[i][0].position += p.velocity * elapsed.asSeconds();
			m_vertices[i][1].position += p.velocity * elapsed.asSeconds();
			m_vertices[i][2].position += p.velocity * elapsed.asSeconds();
			m_vertices[i][3].position += p.velocity * elapsed.asSeconds();

			float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
		}
	}

	bool allDead = true;

	for (std::size_t i = 0; i < m_particles.size(); ++i)
	{
		Particle& p = m_particles[i];

		if (p.lifetime > sf::Time::Zero)
		{
			allDead = false;
		}
	}

	if (allDead)
	{
		m_startPlay = false;
	}
}

bool ParticleSystem::isPlaying()
{
	return m_startPlay;
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// on applique la transformation
	states.transform *= getTransform();

	// nos particules n'utilisent pas de texture
	states.blendMode = sf::BlendAdd;

	// on dessine enfin le vertex array
	for (int i = 0; i < m_particles.size(); ++i)
	{
		states.texture = m_particles[i].texture;

		target.draw(m_vertices[i], states);
	}
}


void ParticleSystem::resetParticle(std::size_t index)
{
	//m_particles.erase(m_particles.begin() + index);
}