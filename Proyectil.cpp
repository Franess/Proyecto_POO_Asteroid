#include "Proyectil.h"
#include <cmath>

Proyectil::Proyectil(Vector2f set_p, float nave_rotation) {
	
	m_formaProye.setPointCount(3);
	m_formaProye.setRadius(3);
	m_formaProye.setOrigin(3,3);
	m_formaProye.setFillColor({255,255,255});
	
	m_formaProye.setRotation(nave_rotation);
	m_formaProye.setPosition(set_p);
}

void Proyectil::actualizar(){
	float radianes_rot = m_formaProye.getRotation()*M_PI/180;
	m_formaProye.move(3*cos(radianes_rot-M_PI/2),3*sin(radianes_rot-M_PI/2));
}

void Proyectil::dibujar(RenderWindow &win){
	win.draw(m_formaProye);
}
 Vector2f Proyectil::obtenerPosicion()const{
	return m_formaProye.getPosition();
}
