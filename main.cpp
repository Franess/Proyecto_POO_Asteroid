#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "asteroide.h"
#include "complemento_v.h"
#include <SFML/Graphics/Color.hpp>
#include <vector>
#include "ast_manip.h"
#include <SFML/Graphics/Texture.hpp>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow win(VideoMode((640),(360)),"Asteroid");
	win.setFramerateLimit(60);
	Texture* tex_asteroide= new Texture; 			//make_shared es un gestor mas eficiente y seguro que un new Texture, pero en poo dimos new asi que usamo new
	(*tex_asteroide).loadFromFile("asteroide.png");	//convendria usar shared_ptr para ahorrarnos la eliminacion del puntero
	vector <asteroide> ast;
	
	
	Nave navesita(40,3);
	int prueba=0;									//simplemente para probar el sistema de respawn de asteroides;

	while(win.isOpen()) {
		Event e;
		while(win.pollEvent(e)) {
			if(e.type == Event::Closed){
				delete tex_asteroide;
				win.close();
			}
		}
		win.clear(Color(40,40,50,255));
		
		prueba++;
		if (prueba>20){
			spawn(ast,tex_asteroide);
			respawn(ast);
			prueba=0;
		} 
		colision(ast);
		for(int i=0;i<ast.size();i++) {  
			ast[i].actualizar();
			ast[i].dibujar(win);
		}
		navesita.actualizar();
		navesita.dibujar(win);
		
		win.display();
	}
	delete tex_asteroide;
	return 0;
}

