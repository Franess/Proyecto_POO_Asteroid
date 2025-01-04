#include "Proyectil.h"

Proyectil::Proyectil() {
	m_formaProye.setPointCount(3);
	m_formaProye.setRadius(3);
	m_formaProye.setOrigin(3,3);
	m_formaProye.setFillColor({255,255,255});
}

void Proyectil::actualizar(){
	
}

void Proyectil::dibujar(RenderWindow &win){
	win.draw(m_formaProye);
}
