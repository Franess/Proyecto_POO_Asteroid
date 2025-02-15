#ifndef ESCENAARCHIVOS_H
#define ESCENAARCHIVOS_H
#include "Escena.h"

class EscenaArchivos : public Escena {
public:
	EscenaArchivos();
	void Actualizar (Juego & j)override;
	void Dibujar (sf::RenderWindow & win)override;
	void ProcesarEvento (Juego & j, sf::Event e)override;
	~EscenaArchivos()override;
private:
};

#endif

