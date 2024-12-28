#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "asteroide.h"
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow win(VideoMode(640,360),"Asteroid");
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

