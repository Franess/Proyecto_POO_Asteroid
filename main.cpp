#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "asteroide.h"
#include "complemento_v.h"
#include <SFML/Graphics/Color.hpp>
#include "Settings.h"
#include <vector>
#include "ast_manip.h"
#include <SFML/Graphics/Texture.hpp>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow win(VideoMode((640),(360)),"Asteroid");
	win.setFramerateLimit(60);
	Settings sett;
	Nave navesita(sett);
	Texture* tex_asteroide= new Texture; 			//make_shared es un gestor mas eficiente y seguro que un new Texture, pero en poo dimos new asi que usamo new
	(*tex_asteroide).loadFromFile("asteroide.png");	//convendria usar shared_ptr para ahorrarnos la eliminacion del puntero
	vector <asteroide> ast;
	int prueba=0;									//simplemente para probar el sistema de respawn de asteroides;
	vector<Proyectil> proye_pantalla;
 	
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
		for(int i=0;i<ast.size();i++) {  
			ast[i].actualizar();
			ast[i].dibujar(win);
		}
		if(navesita.disparar()){
			proye_pantalla.push_back(navesita.generarDisparo());
		}
		for(Proyectil &x:proye_pantalla){
			x.actualizar();
			x.dibujar(win);
		} 
		navesita.actualizar();
		navesita.dibujar(win);
		
		win.display();
	}
	return 0;
}

