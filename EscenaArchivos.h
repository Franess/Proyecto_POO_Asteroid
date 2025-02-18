#ifndef ESCENAARCHIVOS_H
#define ESCENAARCHIVOS_H
#include "funcionesBotones.h"
#include <stdexcept>
#include <fstream>
#include "Escena.h"
#include "Settings.h"
#include "Boton.h"
#include "PantallaInicio.h"

class EscenaArchivos : public Escena {
public:
	EscenaArchivos(int selector_escenaSig);
	void Actualizar (Juego & j)override;
	void Dibujar (sf::RenderWindow & win)override;
	void ProcesarEvento (Juego & j, sf::Event e)override;
	~EscenaArchivos()override;
private:
	sf::Text m_tituloPantalla, m_indicadorArchivo, m_indicadorEstado;
	sf::RectangleShape m_seccionTitulo;
	sf::Font m_fuente;
	Settings m_settings;
	std::vector<bool> m_estadosArchivos;
	std::vector<Boton> m_vecbotones;
	std::vector<sf::Text> m_textosEstados;
	vector<float> m_escalas;
	int contador_estados;
};

#endif

