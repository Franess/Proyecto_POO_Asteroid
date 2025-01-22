#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics.hpp>
class juego;

class Escena
{
public:
	virtual void Actualizar()=0;
	virtual void Dibujar(sf::RenderWindow &win)=0;
};

#endif
