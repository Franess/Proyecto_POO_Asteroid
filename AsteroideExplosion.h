#ifndef ASTEROIDEEXPLOSION_H
#define ASTEROIDEEXPLOSION_H
#include "Efecto.h"
#include <SFML/Graphics.hpp>
#include <vector>

class AsteroideExplosion : public Efecto {
public:
	AsteroideExplosion(float aste_radio, sf::Vector2f pos_aste);
	sf::Vector2f generarVectorMove();
	void actualizar ( );
	void dibujar (sf::RenderWindow & win);
private:
	std::vector<sf::CircleShape> m_vecParticulas;
};

#endif

