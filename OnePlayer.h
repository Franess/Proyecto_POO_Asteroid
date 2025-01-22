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
#include <algorithm>
#include "ast_manip.h"
using namespace std;

class OnePlayer : public Escena {
public:
	OnePlayer(Settings &s);
	void Actualizar (Juego &j)override;
	void Dibujar (sf::RenderWindow & win)override;
	~OnePlayer();
private:
	Nave m_navesita;
	Texture* mtex_asteroide; 			
	vector <asteroide> m_ast;
	int m_prueba=0;
	vector<Proyectil> mproye_pantalla;
	vector<AsteroideExplosion> mefec_explosion;
	Efecto *m_vfx = nullptr;
};

#endif

