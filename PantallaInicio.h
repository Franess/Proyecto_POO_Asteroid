#ifndef PANTALLAINICIO_H
#define PANTALLAINICIO_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include "Boton.h"

class PantallaInicio : public Escena {
public:
	PantallaInicio();
	void Actualizar (Juego & j);
	void Dibujar (sf::RenderWindow & win);
	void ProcesarEvento(Juego &j, sf::Event e)override;
	~PantallaInicio();
private:
	sf::Text m_comienzoNombre, m_finalNombre;
	sf::Sprite m_imagenAsteroide;
	sf::Font m_fuente;
	sf::Texture m_textura;
	vector<Boton> vec_botones;
};

#endif

