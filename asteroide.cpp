#include "asteroide.h"
#include "rng.h"
/*los valores min y max de rng para x,y deben cambiarse por una vez implementado el movimiento hacia el centro	
0	->	-30
640	->	670
360	->	390
*/
using namespace std;
asteroide::asteroide() {
	tex.loadFromFile("asteroide.png");
	spr.setTexture(tex);
	spr.setOrigin(10,10);
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
		x=RNG(640,0);	
		if (y>0){
			y=360;
		}else{
			y=0;		
		}
	}else{
		if (y>0){
			x=640;
		}
		else{
			x=0;		
		}
		y=RNG(360,0);
	}
	spr.setPosition(x,y);
	
}
