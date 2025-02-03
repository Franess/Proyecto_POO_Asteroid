#include "menu_ajustes.h"
#include "funcionesBotones.h"

menu_ajustes::menu_ajustes() {
	m_fuente.loadFromFile("SixtyfourConvergence-Regular-VariableFont_BLED,SCAN,XELA,YELA.ttf");
	Boton boton_controles("Controles",&m_fuente,20);
	boton_controles.escalado(0.5,1.f);
	boton_controles.establecerPosicion(50,20);
	vec_botones.push_back(boton_controles);
	
	Boton boton_ajuego("Juego",&m_fuente,20);
	boton_ajuego.escalado(0.5,1.f);
	boton_ajuego.establecerPosicion(30,60);
	vec_botones.push_back(boton_ajuego);
}

void menu_ajustes::Actualizar (Juego & j) {
	
}

void menu_ajustes::Dibujar (sf::RenderWindow & win) {
	m_escalas = actualizarEscalares(win);
	for(Boton &x:vec_botones)x.dibujar(win);
}

void menu_ajustes::ProcesarEvento (Juego & j, sf::Event e) {
	if(e.type == sf::Event::MouseMoved)
	{
		sf::Vector2f pos_mouse(e.mouseMove.x,e.mouseMove.y);
		for(Boton &x:vec_botones){
			if(calculo_sobreposicion(pos_mouse,x,m_escalas[0],m_escalas[1]))
			{ 
				x.colorFondo({190,255,250,50});
			}
			else x.colorFondo({0,0,0,0});
		}
	}
}

