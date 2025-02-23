#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include "Escena.h"

class Juego {
public:
	Juego(Escena *e);
	void jugar();
	void CambiarEscena(Escena *nueva);
	void terminar();
	~Juego();
private:
	sf::RenderWindow m_win;
	Escena *m_escenaActual, *m_escenaSiguiente=nullptr;
	bool pantalla_completa;
	sf::View vista;
};

#endif

