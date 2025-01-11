#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "asteroide.h"
#include "complemento_v.h"
#include <SFML/Graphics/Color.hpp>
#include "Settings.h"
#include <vector>
#include "ast_manip.h"
#include <SFML/Graphics/Texture.hpp>
#include <algorithm>
#include "Proyectil.h"
using namespace std;
using namespace sf;

bool fuera_limites(Proyectil &d){
	Vector2f pos_actual = d.obtenerPosicion();
	if(pos_actual.x<0 or pos_actual.x>640)
		return true;
	if(pos_actual.y<0 or pos_actual.y>360) 
		return true;
	return false;
}
bool colision_naveaste(Nave &n, asteroide &a){
	Vector2f vec_foco1 = n.obtenerFoco1() - a.get_posicion();
	Vector2f vec_foco2 = n.obtenerFoco2() - a.get_posicion();
	float limiteNorma_foco1 = n.obtenerRadioFoco1() + a.get_rad(); 
	float limiteNorma_foco2 = n.obtenerRadioFoco2() + a.get_rad();
	float norma_foco1 = sqrt(vec_foco1.x*vec_foco1.x + vec_foco1.y*vec_foco1.y);
	float norma_foco2 = sqrt(vec_foco2.x*vec_foco1.x + vec_foco2.y*vec_foco2.y);
	if(norma_foco1<=limiteNorma_foco1 || norma_foco2<=limiteNorma_foco2 )
		return true;
	else
		return false;
	
}

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
		destruir(ast,proye_pantalla);
		colision(ast);
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
		//remueve el proyectil que se encuentra fuera de los limites de la pantalla de juego
		auto it_elimproye = remove_if(proye_pantalla.begin(),proye_pantalla.end(),fuera_limites);	//elimproye => eliminar proyectil
		proye_pantalla.erase(it_elimproye,proye_pantalla.end());
		
		auto it_colisionAsteNave = find_if(ast.begin(),ast.end(),[&navesita](asteroide &a){return colision_naveaste(navesita,a);});
		if(it_colisionAsteNave!=ast.end() && navesita.obtenerInmunidad()){
			(*it_colisionAsteNave).r_size();
			(*it_colisionAsteNave).cambiar_objetivo();
			(*it_colisionAsteNave).reposicionar();
			(*it_colisionAsteNave).set_direccion();
			navesita.respawn();
		}
		
		navesita.actualizar();
		navesita.dibujar(win);
		
		win.display();
	}
	return 0;
}
	
