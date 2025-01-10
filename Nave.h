#ifndef NAVE_H
#define NAVE_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Settings.h"
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include "Proyectil.h"
using namespace std;
using namespace sf;
class Nave{
public:
	Nave(Settings &s);
	void actualizar();
	void dibujar(RenderWindow &win);
	bool disparar();
	Proyectil generarDisparo()const;
	
private:
	ConvexShape m_nave;
	vector<Keyboard::Key> m_teclas;
	float elapsed_time=0;
	Vector2f m_vecDireccion;
	float radianes_rot;
};
#endif

