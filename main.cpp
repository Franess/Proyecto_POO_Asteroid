#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "asteroide.h"
#include "complemento_v.h"
#include <SFML/Graphics/Color.hpp>
using namespace sf;

void respawn(asteroide &a){
	if ( (a.posicion()> Vector2f(640+10,360+10))or(Vector2f(0-10,0-10)>a.posicion()) ){
	a.cambiar_objetivo();
	a.reposicionar();
}
};


int main(int argc, char *argv[]){
	RenderWindow win(VideoMode((640),(360)),"Asteroid");
	win.setFramerateLimit(60);
	asteroide ast;
	ast.cambiar_objetivo();
	ast.reposicionar();
	
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
		if (prueba>20){
			respawn(ast);
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

