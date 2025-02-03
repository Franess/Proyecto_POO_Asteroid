#ifndef ONEPLAYER_H
#define ONEPLAYER_H
#include "Escena.h"
#include "Settings.h"
#include "Nave.h"
#include <vector>
#include "Efecto.h"
#include "AsteroideExplosion.h"
#include "Juego.h"
#include "OndaConcentrica.h"
#include <cmath>
#include <SFML/Audio.hpp>
#include <algorithm>
#include "ast_manip.h"
#include "Boton.h"
#include "tabla_de_puntos.h"
#include "JuegoTerminado.h"
#include "PantallaInicio.h"
#include "musica.h"
using namespace std;

class OnePlayer : public Escena {
public:
	OnePlayer(Settings &s);
	void Actualizar (Juego &j)override;
	void Dibujar (sf::RenderWindow & win)override;
	void ProcesarEvento(Juego &j, sf::Event e)override;
	~OnePlayer();
private:
	Nave m_navesita;
	Texture* mtex_asteroide; 			
	vector <asteroide> m_ast;
	tabla_de_puntos m_tabla;
	int m_prueba=0;
	int m_puntos_para_siguiente=75;
	vector<Proyectil> mproye_pantalla;
	vector<AsteroideExplosion> mefec_explosion;
	Efecto *m_vfx = nullptr;
	sf::Font m_fuente;
	sf::Text m_msjTeclaMenu;
	vector<Boton> vec_botones;
	//musica m_musica;
	sf::Music m_musica;
};

#endif

