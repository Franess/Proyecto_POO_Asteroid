#ifndef MENU_AJUSTES_H
#define MENU_AJUSTES_H
#include "Escena.h"
#include "Settings.h"
#include "Boton.h"

class menu_ajustes : public Escena {
public:
	menu_ajustes();
	void Actualizar (Juego & j);
	void Dibujar (sf::RenderWindow & win);
	void ProcesarEvento (Juego & j, sf::Event e);
private:
	Settings m_settings;
	std::vector<Boton> vec_botones;
	sf::Font m_fuente;
	vector<float> m_escalas;
};

#endif

