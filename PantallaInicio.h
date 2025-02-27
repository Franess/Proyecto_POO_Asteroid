#ifndef PANTALLAINICIO_H
#define PANTALLAINICIO_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include "Boton.h"
#include "menu_ajustes.h"
#include <algorithm>
#include "OnePlayer.h"
#include "Settings.h"
#include "Escena_Puntaje.h"
#include "funcionesBotones.h"
#include <SFML/Audio.hpp>

class PantallaInicio : public Escena {
public:
	PantallaInicio();
	void Actualizar (Juego & j)override;
	void Dibujar (sf::RenderWindow & win)override;
	void ProcesarEvento(Juego &j, sf::Event e)override;
	~PantallaInicio()override;
private:
	sf::Text m_comienzoNombre, m_finalNombre, m_mensajeSalir;
	sf::Sprite m_imagenAsteroide, m_sprFondo;
	sf::Font m_fuente;
	sf::Texture m_textura, m_imgFondo;
	vector<Boton> vec_botones;
	vector<float> m_escalas;
	sf::Music m_musica;
	bool boton_presionado;
};

#endif

