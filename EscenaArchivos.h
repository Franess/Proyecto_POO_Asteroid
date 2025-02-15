#ifndef ESCENAARCHIVOS_H
#define ESCENAARCHIVOS_H
#include "Escena.h"

class EscenaArchivos : public Escena {
public:
	EscenaArchivos(int selector_escenaSig);
	void Actualizar (Juego & j)override;
	void Dibujar (sf::RenderWindow & win)override;
	void ProcesarEvento (Juego & j, sf::Event e)override;
	~EscenaArchivos()override;
private:
	sf::Text m_tituloPantalla;
	sf::RectangleShape m_seccionTitulo;
	sf::Font m_fuente;
};

#endif

