#include "Juego.h"
#include <iostream>
#include "Escena.h"

using namespace std;

Juego::Juego(Escena* e):m_win(sf::VideoMode((640),(360)),"Asteroid"),vista(sf::FloatRect(0,0,640,360)){
	m_win.setFramerateLimit(60);
	m_escenaActual=e;
	pantalla_completa=0;
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
				if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::F11)
				{
					pantalla_completa = !pantalla_completa;
					if(pantalla_completa==0){
						
						
					}else{
						sf::VideoMode aux = sf::VideoMode::getDesktopMode();
						
						vista.setSize(aux.width,aux.height);
						m_win.create(aux,"Asteroid",sf::Style::Fullscreen);
						cout<<aux.height;
						vista.zoom(1.f/(aux.height/360));
						m_win.setView(vista);
						
					}
				}
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

