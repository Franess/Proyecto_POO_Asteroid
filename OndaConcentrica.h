#ifndef ONDACONCENTRICA_H
#define ONDACONCENTRICA_H
#include "Efecto.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class OndaConcentrica : public Efecto {
public:
	OndaConcentrica(Vector2f pos_centro);
	void actualizar( )override;
	void dibujar(RenderWindow & win)override;
private:
	sf::Vector2f m_cir1;
	sf::Vector2f m_cir2;
	sf::Vector2f m_cir3;
	sf::Vector2f m_centro;
};

#endif

