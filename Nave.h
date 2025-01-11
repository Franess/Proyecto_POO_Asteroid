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
	Vector2f obtenerFoco1()const;//El menor
	Vector2f obtenerFoco2()const;//El mayor
	float obtenerRadioFoco1()const;
	float obtenerRadioFoco2()const;
	void respawn();
private:
	ConvexShape m_nave;
	vector<Keyboard::Key> m_teclas;
	float time_pressed=0;
	Vector2f m_vecDireccion;
	float radianes_rot;
	float m_radio; //Es el radio de una circunferencia imaginaria al rededor de la nave.
};
#endif

