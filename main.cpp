#include <SFML/Graphics.hpp>
#include "Nave.h"
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(800,600),"Ejemplo de SFML");
	w.setFramerateLimit(60);
	
	Nave navesita(40,3);
		
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		w.clear(Color(255,255,255,255));
		navesita.actualizar();
		navesita.dibujar(w);
		
		w.display();
	}
	return 0;
}

