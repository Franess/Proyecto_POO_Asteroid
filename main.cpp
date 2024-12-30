#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "asteroide.h"
#include "complemento_v.h"
#include <SFML/Graphics/Color.hpp>
#include <vector>
using namespace std;
using namespace sf;

void respawn(vector<asteroide> &a){
	for(int i=0;i<a.size();i++) { 
		if ( (a[i].posicion()> Vector2f(640+10,360+10))or(Vector2f(0-10,0-10)>a[i].posicion()) ){
			a[i].cambiar_objetivo();
			a[i].reposicionar();
		}
	}
};


int main(int argc, char *argv[]){
	RenderWindow win(VideoMode((640),(360)),"Asteroid");
	win.setFramerateLimit(60);
	vector <asteroide> ast(15);
	for(int i=0;i<ast.size();i++) { 
		ast[i].cambiar_objetivo();
		ast[i].reposicionar();	
	}
	
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
		for(int i=0;i<ast.size();i++) {  
			ast[i].actualizar();
			ast[i].dibujar(win);
		}
	navesita.actualizar();
		navesita.dibujar(win);
		
		win.display();
	}
	return 0;
}

