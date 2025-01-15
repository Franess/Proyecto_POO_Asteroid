#ifndef EFECTO_H
#define EFECTO_H
#include <SFML/Graphics.hpp>

class Efecto{
public:
	virtual void actualizar()=0;
	virtual void dibujar(sf::RenderWindow &win)=0;
};
#endif
