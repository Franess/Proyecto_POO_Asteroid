#ifndef ESCENA_PUNTAJE_H
#define ESCENA_PUNTAJE_H
#include "tabla_de_puntos.h"
#include <vector>
#include "Escena.h"
#include <SFML/Graphics.hpp>
using namespace std;

class Escena_Puntaje : public Escena {
public:
	Escena_Puntaje();
	void Actualizar (Juego &j)override;
	void Dibujar (sf::RenderWindow & win)override;
	void ProcesarEvento(Juego &j, sf::Event e)override;
	~Escena_Puntaje();
private:
	vector<puntaje> m_puntos;
	sf::Font m_fuente;
	vector<sf::Text> m_text;
};

#endif

