#include "Escena_Puntaje.h"
#include <SFML/System/Vector2.hpp>
Escena_Puntaje::Escena_Puntaje ( ) {
tabla_de_puntos tabla;
m_puntos=tabla.cargar_lista();
m_fuente.loadFromFile("Roboto_Condensed-Bold.ttf");
sf::Vector2i posicion(640/2,130);
for(int i=0;i<10;i++) { 
	m_puntos[i];
}
}

void Escena_Puntaje::Actualizar (Juego & j) {
	
}

void Escena_Puntaje::Dibujar (sf::RenderWindow & win) {
	
}

void Escena_Puntaje::ProcesarEvento (Juego & j, sf::Event e) {
	
}

Escena_Puntaje::~Escena_Puntaje ( ) {
	
}

