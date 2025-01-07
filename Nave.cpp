#include "Nave.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include "Settings.h"
using namespace std;
using namespace sf;


Nave::Nave(Settings &s)
{
	m_nave.setPointCount(4);
	//Definen la posicion de los vertices de la nava
	m_nave.setPoint(0,Vector2f(10,0));
	m_nave.setPoint(1,Vector2f(20,30));
	m_nave.setPoint(2,Vector2f(10,20));
	m_nave.setPoint(3,Vector2f(0,30));
	//El diseño esta pensado para tener un tamanio de 20x30 pixeles
	m_nave.setOutlineThickness(2);
	m_nave.setOutlineColor({255,255,255,255});
	
	m_nave.setOrigin(10,15);
	m_nave.setPosition(100,100);
	m_nave.setFillColor({239,254,0,128});
	m_teclas = s.obtenerControles();
}

void Nave::actualizar()
{
	if(Keyboard::isKeyPressed(m_teclas[1]))//rotar derecha
		m_nave.rotate(2);
	if(Keyboard::isKeyPressed(m_teclas[2]))//Rotar izquierda
		m_nave.rotate(-2);	
	if(Keyboard::isKeyPressed(m_teclas[3])){	//Avanzar nave
		float radianes_rot = m_nave.getRotation()*M_PI/180;
		m_nave.move(2*cos(radianes_rot-M_PI/2),2*sin(radianes_rot-M_PI/2));
	}
}
void Nave::dibujar(RenderWindow &win)
{
	win.draw(m_nave);
}

bool Nave::disparar(){
	if(Keyboard::isKeyPressed(m_teclas[0])){
		return true;
	}else{
		return false;
	}
}

Proyectil Nave::generarDisparo()const{
	Proyectil proye(m_nave.getPosition(),m_nave.getRotation());
	return proye;
}
