#include "OndaConcentrica.h"
#include "Efecto.h"
using namespace std;
using namespace sf;

OndaConcentrica::OndaConcentrica(Vector2f pos_centro, float radio_nave):m_maxRadio(radio_nave) {
	m_circInter.setOrigin(0,0);
	m_circMed.setOrigin(0,0);
	m_circExtern.setOrigin(0,0);
	
	m_circInter.setPosition(pos_centro);
	m_circMed.setPosition(pos_centro);
	m_circExtern.setPosition(pos_centro);
	m_transparencia=255;
	
	m_circInter.setFillColor({255,255,255,0});
	m_circMed.setFillColor({255,255,255,0});
	m_circExtern.setFillColor({255,255,255,0});
	
	m_circInter.setOutlineThickness(2);
	m_circMed.setOutlineThickness(2);
	m_circExtern.setOutlineThickness(2);
}
void OndaConcentrica::actualizar(){
	Color color_borde(255,255,255,m_transparencia);
	m_circInter.setOutlineColor(color_borde);
	m_circMed.setOutlineColor(color_borde);
	m_circExtern.setOutlineColor(color_borde);
	
	m_circInter.setOrigin(m_acumulador*(1.0/3),m_acumulador*(1.0/3));
	m_circMed.setOrigin(m_acumulador*(2.0/3),m_acumulador*(2.0/3));
	m_circExtern.setOrigin(m_acumulador,m_acumulador);

	
	m_circInter.setRadius(m_acumulador*(1.0/3));
	m_circMed.setRadius(m_acumulador*(2.0/3));
	m_circExtern.setRadius(m_acumulador);
	if(m_acumulador<2*m_maxRadio){
		m_acumulador+=(1.0/6);
	}
	if(m_transparencia<=255){
		m_transparencia-=(17.0/12);
	}
}
void OndaConcentrica::dibujar(RenderWindow &win){
	win.draw(m_circInter);
	win.draw(m_circMed);
	win.draw(m_circExtern);
}

