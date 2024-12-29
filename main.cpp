#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "asteroide.h"
using namespace sf;

int main(int argc, char *argv[]){
	//640x360 resolucion real,  10% exra solo con fines de visualizacion de elementos fuera de pantalla 
	RenderWindow win(VideoMode(64+640,36+360),"Asteroid");
	win.setFramerateLimit(60);
	asteroide a;
	Nave navesita(40,3);


	while(win.isOpen()) {
		Event e;
		while(win.pollEvent(e)) {
			if(e.type == Event::Closed)
				win.close();	
		}
		
		
		win.clear(Color(40,40,50,255));
		
		a.actualizar();
		navesita.actualizar();
		navesita.dibujar(win);
		a.dibujar(win);
		
		
		win.display();
	}
	return 0;
}

