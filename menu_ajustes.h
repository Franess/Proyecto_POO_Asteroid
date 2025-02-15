#ifndef MENU_AJUSTES_H
#define MENU_AJUSTES_H
#include <SFML/Graphics.hpp>
#include "Escena.h"
#include "Settings.h"
#include "Boton.h"
#include "PantallaInicio.h"
#include <sstream>

class menu_ajustes : public Escena {
public:
	menu_ajustes();
	void Actualizar (Juego & j)override;
	void Dibujar (sf::RenderWindow & win)override;
	void ProcesarEvento (Juego & j, sf::Event e)override;
	~menu_ajustes()override;
private:
	int m_selectorContenidos=1;
	Settings m_settings;
	sf::Font m_fuente;
	sf::RectangleShape m_divisor, m_recuadroTitulo;
	sf::Text m_titulo, m_avisoTeclaSalir, m_avisoGuardadoCtrl, m_avisoGuardadoJuego, m_textoVidas;
	vector<float> m_escalas;
	std::vector<string> m_controlesActuales; 
	Boton m_btnsumar, m_btnrestar;
	std::vector<Boton> vec_botones;
	std::vector<Boton> selec_cambiosCtrl;
	std::vector<sf::Text> textos_controles;
	std::vector<sf::Text> txt_configJuego;
	std::vector<std::string> stringControles;
	InputText m_textoEntrada;
	vector<Config> m_configuraciones;
};

#endif

