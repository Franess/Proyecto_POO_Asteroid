#ifndef MENU_AJUSTES_H
#define MENU_AJUSTES_H
#include <SFML/Graphics.hpp>
#include "Escena.h"
#include "Settings.h"
#include "Boton.h"
#include "PantallaInicio.h"

class menu_ajustes : public Escena {
public:
	menu_ajustes();
	void Actualizar (Juego & j);
	void Dibujar (sf::RenderWindow & win);
	void ProcesarEvento (Juego & j, sf::Event e);
private:
	int m_selectorContenidos=1;
	Settings m_settings;
	sf::Font m_fuente;
	sf::RectangleShape m_divisor, m_recuadroTitulo;
	sf::Text m_titulo, m_avisoTeclaSalir, m_avisoGuardadoCtrl, m_avisoGuardadoJuego;
	vector<float> m_escalas;
	std::vector<string> m_controlesActuales; 
	std::vector<Boton> vec_botones;
	std::vector<Boton> selec_cambiosCtrl;
	std::vector<sf::Text> textos_controles;
	std::vector<std::string> stringControles;
	InputText m_textoEntrada;
};

#endif

