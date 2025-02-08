#include "Juego.h"
#include <iostream>
#include "Escena.h"

#include <typeinfo>
using namespace std;

Juego::Juego(Escena* e):m_win(sf::VideoMode((640),(360)),"Asteroid") {
	m_win.setFramerateLimit(60);
	m_escenaActual=e;
}
Juego::~Juego()
{
	delete m_escenaActual;
}
void Juego::CambiarEscena(Escena *nueva){
	m_escenaSiguiente = nueva;
}
void Juego::jugar()
{
	while(m_win.isOpen()) {
		sf::Event e;
		while(m_win.pollEvent(e)) {
			if(e.type == sf::Event::Closed){
				m_win.close();
			}else
			{
				m_escenaActual->ProcesarEvento(*this,e);
			}
		}
		m_win.clear(sf::Color(0,0,0,255));
		m_escenaActual->Actualizar(*this);
		m_escenaActual->Dibujar(m_win);
		m_win.display();
		if(m_escenaSiguiente)
		{
			delete m_escenaActual;
			m_escenaActual = m_escenaSiguiente;
			m_escenaSiguiente = nullptr;
		}
		
	}
}
void Juego::terminar()
{
	m_win.close();
}
