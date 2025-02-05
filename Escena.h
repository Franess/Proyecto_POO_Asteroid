#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics.hpp>
#include "InputText.hpp"
class Juego;

class Escena
{
public:
	virtual void Actualizar(Juego &j)=0;
	virtual void Dibujar(sf::RenderWindow &win)=0;
	virtual void ProcesarEvento(Juego &j, sf::Event e)=0;
};

#endif
