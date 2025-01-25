#include "PantallaInicio.h"

PantallaInicio::PantallaInicio() 
{
	m_fuente.loadFromFile("Roboto_Condensed-Bold.ttf");
	m_textura.loadFromFile("asteroide.png");
	m_imagenAsteroide.setTexture(m_textura);
	m_comienzoNombre.setFont(m_fuente);
	m_finalNombre.setFont(m_fuente);
	
	m_comienzoNombre.setCharacterSize(50);
	m_finalNombre.setCharacterSize(50);
	m_comienzoNombre.setFillColor({255,255,255});
	m_finalNombre.setFillColor({255,255,255});
	m_comienzoNombre.setString("Aster");
	m_finalNombre.setString("ids");
	m_comienzoNombre.setOrigin(0,0);
	m_finalNombre.setOrigin(0,0);
	m_comienzoNombre.setPosition(205,60);
	m_finalNombre.setPosition(365,60);
	
	m_imagenAsteroide.setScale(2.f,2.f);
	m_imagenAsteroide.setOrigin(0,0);
	m_imagenAsteroide.setPosition(340,95);
	sf::Rect<float> aux_Bordesimg = m_imagenAsteroide.getLocalBounds();
	m_imagenAsteroide.setOrigin((aux_Bordesimg.height)/2,(aux_Bordesimg.height)/2);
	
	Boton nuevo_boton("Jugar",&m_fuente,30);
	nuevo_boton.establecerPosicion(320,240);
	vec_botones.push_back(nuevo_boton);
	Boton nuevo_boton1("Puntaje",&m_fuente,30);
	nuevo_boton1.establecerPosicion(320,300);
	vec_botones.push_back(nuevo_boton1);
	
	
	
}

void PantallaInicio::Actualizar (Juego & j) {
	m_imagenAsteroide.rotate(3);
}

void PantallaInicio::Dibujar (sf::RenderWindow & win) {
	win.clear({0,0,0});
	win.draw(m_comienzoNombre);
	win.draw(m_finalNombre);
	win.draw(m_imagenAsteroide);
	for(Boton &x:vec_botones){
		x.dibujar(win);
	}
}
PantallaInicio::~PantallaInicio()
{
	
}
