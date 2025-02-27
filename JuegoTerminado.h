#ifndef JUEGOTERMINADO_H
#define JUEGOTERMINADO_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include "tabla_de_puntos.h"
#include "Boton.h"
#include "PantallaInicio.h"
#include "Juego.h"
#include <SFML/Audio.hpp>

class JuegoTerminado : public Escena {
public:
	JuegoTerminado(int puntos_fin);
	void Actualizar (Juego & j)override;
	void Dibujar (sf::RenderWindow & win)override;
	void ProcesarEvento (Juego & j, sf::Event e)override;
	~JuegoTerminado()override;
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
	sf::Music m_musica;
};

#endif

