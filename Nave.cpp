#include "Nave.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include "Settings.h"
using namespace std;
using namespace sf;


Nave::Nave(float r, int p,const Settings &s)  {
	m_nave.setRadius(r);
	m_nave.setPointCount(p);
	m_nave.setOrigin(r,r);
	m_nave.setOutlineThickness(2);
	m_nave.setOutlineColor({0,0,0});
	
	m_nave.setPosition(100,100);
	m_nave.setFillColor({239,254,0});
	m_teclas = s.obtenerTeclas();
}
void Nave::actualizar()
{
	if(Keyboard::isKeyPressed(Keyboard::W)){
		float radianes_rot = m_nave.getRotation()*M_PI/180;
		m_nave.move(2*cos(radianes_rot-M_PI/2),2*sin(radianes_rot-M_PI/2));
	}
	if(Keyboard::isKeyPressed(Keyboard::A))
		m_nave.rotate(-2);
	if(Keyboard::isKeyPressed(m_teclas[0]))
		m_nave.rotate(2);
	
}
void Nave::dibujar(RenderWindow &win)
{
	win.draw(m_nave);
}
