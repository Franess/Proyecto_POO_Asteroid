#include "asteroide.h"
#include "rng.h"

using namespace std;
asteroide::asteroide() {
	tex.loadFromFile("asteroide.png");
	spr.setTexture(tex);
	
	/*int x=RNG(1), y= RNG(1);
	if (x>0){
		x=RNG(640,0);	//0 debe cambiarse por -20 una vez implementado el movimiento hacia el centro
		if (y>0){
			y=360;
		}else{
			y=0;		//aca tambien
		}
	}else{
		if (y>0){
			x=640;
		}
		else{
			x=0;		//aca tambien
		}
		y=RNG(360,0);	//aca tambien
	}
	spr.setPosition(x,y);*/
}
void asteroide::actualizar(){
spr.move(0,0);	
}
void asteroide::dibujar(RenderWindow &win){
	win.draw(spr);
}
void asteroide::reposicionar(){
	
	int x=RNG(1), y= RNG(1);
	if (x>0){
		x=RNG(640,0);	//0 debe cambiarse por -20 una vez implementado el movimiento hacia el centro
		if (y>0){
			y=360;
		}else{
			y=0;		//aca tambien
		}
	}else{
		if (y>0){
			x=640;
		}
		else{
			x=0;		//aca tambien
		}
		y=RNG(360,0);	//aca tambien
	}
	spr.setPosition(x,y);
	
}
