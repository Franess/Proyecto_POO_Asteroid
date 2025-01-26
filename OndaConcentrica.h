#ifndef ONDACONCENTRICA_H
#define ONDACONCENTRICA_H
#include <SFML/Graphics.hpp>
#include "Efecto.h"
class OndaConcentrica : public Efecto {
public:
	OndaConcentrica(sf::Vector2f pos_centro, float radio_nave);
	void actualizar()override;
	void dibujar(sf::RenderWindow &win)override;
private:
	sf::CircleShape m_circInter;
	sf::CircleShape m_circMed;
	sf::CircleShape m_circExtern;
	float m_transparencia, m_radioInter,m_radioMed, m_radioExtern,m_acumulador=0;
	float m_maxRadio=0;
};

#endif

