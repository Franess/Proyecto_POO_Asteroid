#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "asteroide.h"
using namespace sf;

int main(int argc, char *argv[]){
	
	RenderWindow win(VideoMode((640),(360)),"Asteroid"); // es el punto centarl
	win.setFramerateLimit(60);
	asteroide ast;
	Nave navesita(40,3);
	int prueba=0;	//simplemente para probar el sistema de respawn de asteroides;

	while(win.isOpen()) {
		Event e;
		while(win.pollEvent(e)) {
			if(e.type == Event::Closed)
				win.close();	
		}
		win.clear(Color(40,40,50,255));
		
		prueba++;
		if (prueba>60*5){
			ast.reposicionar(); 
			prueba=0;
		} 
		ast.actualizar();
		navesita.actualizar();
		navesita.dibujar(win);
		ast.dibujar(win);
		
		win.display();
	}
	return 0;
}

