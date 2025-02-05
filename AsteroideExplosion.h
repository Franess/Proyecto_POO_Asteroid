#ifndef ASTEROIDEEXPLOSION_H
#define ASTEROIDEEXPLOSION_H
#include "Efecto.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Particula.h"
#include "asteroide.h"
#include "Efecto.h"
#include <SFML/Audio.hpp>

class AsteroideExplosion : public Efecto {
public:
	AsteroideExplosion(asteroide &a);
	void actualizar();
	void dibujar (sf::RenderWindow & win);
	int obtenerCantParticulas()const;
	sf::Time obtenerTiempo()const;
	void marcarTiempo();
private:
	std::vector<Particula> m_vecParticulas;
	sf::Clock m_reloj;
	sf::Time m_tiempo;
	sf::Sound m_sound;
	sf::SoundBuffer m_buffer;
};

#endif

