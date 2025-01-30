#ifndef JUEGOTERMINADO_H
#define JUEGOTERMINADO_H
#include "Escena.h"
#include "InputText.hpp"
#include <SFML/Graphics.hpp>
#include "tabla_de_puntos.h"
#include "Boton.h"
#include "PantallaInicio.h"
#include "Juego.h"

class JuegoTerminado : public Escena {
public:
	JuegoTerminado(int puntos_fin);
	void Actualizar (Juego & j);
	void Dibujar (sf::RenderWindow & win);
	void ProcesarEvento (Juego & j, sf::Event e);
private:
	sf::Font m_fuente;
	InputText m_textoEntrada;
	sf::Text m_textoAclaracion,m_tituloPantalla,m_msjTeclaMenu,m_msjFaltaNombre;
	tabla_de_puntos m_tabla;
	std::string m_nombreJugador;
	int m_puntosFinales=0;
	puntaje m_puntajeJugador;
	sf::Texture m_texturaFondo;
	sf::Texture m_texturaNavePixel;
	sf::Sprite m_fondo;
	sf::Sprite m_navePixel;
	Boton m_mostrarPuntos;
	Boton m_btnGuardar;
	std::vector<float> m_escalares;
	
};

#endif

