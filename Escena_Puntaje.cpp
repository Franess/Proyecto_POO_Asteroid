#include "Escena_Puntaje.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "ast_manip.h"
using namespace std;
Escena_Puntaje::Escena_Puntaje ( ) {
tabla_de_puntos tabla;
m_puntos=tabla.cargar_lista();
m_fuente.loadFromFile("SixtyfourConvergence-Regular-VariableFont_BLED,SCAN,XELA,YELA.ttf");
sf::Vector2i posicion(640/2,20);
m_text.resize(10);
mtex_asteroide = new Texture;
(*mtex_asteroide).loadFromFile("asteroide.png");
	for(size_t i=0;i<10;i++) { 
		string aux_n=m_puntos[i].nombre;
		string aux_p=to_string(m_puntos[i].puntos);
		string fill="                    ";
		fill.resize(fill.size()-(aux_n.size()+aux_p.size()));
		m_text[i].setString(aux_n+fill+aux_p);
		m_text[i].setFont(m_fuente);
		m_text[i].setFillColor({255,0,0});
		m_text[i].setCharacterSize(15);
		auto text_size=m_text[i].getLocalBounds();
		m_text[i].setOrigin(text_size.width/2,text_size.height/2);
		m_text[i].setPosition(posicion.x,posicion.y+i*20);
	}
}

void Escena_Puntaje::Actualizar (Juego & j) {
	m_prueba++;
	if (m_prueba%32==0){
		respawn(m_ast,0.5);
		spawn(m_ast,mtex_asteroide,0.5);
	}
	colision(m_ast);
	for(size_t i=0;i<m_ast.size();i++) { 
		m_ast[i].actualizar();
		m_ast[i].set_color(200,200,200);
	}
}

void Escena_Puntaje::Dibujar (sf::RenderWindow & win) {
	win.clear({0,0,0});
	for(size_t i=0;i<m_ast.size();i++) { 
		m_ast[i].dibujar(win);
	}
	for(size_t i=0;i<10;i++) { 
		win.draw(m_text[i]);
	}
}

void Escena_Puntaje::ProcesarEvento (Juego & j, sf::Event e) {
	
}

Escena_Puntaje::~Escena_Puntaje ( ) {
}

