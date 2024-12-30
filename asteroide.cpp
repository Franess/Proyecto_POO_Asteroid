#include "asteroide.h"
#include "rng.h"
#include <cmath>
#include "complemento_v.h"

using namespace std;
asteroide::asteroide() {
	tex.loadFromFile("asteroide.png");
	spr.setTexture(tex);
	spr.setOrigin(10,10);
	spr.setScale(2,2);
	speed=1;
}
Vector2f asteroide::posicion(){
	return spr.getPosition();
}
void asteroide::reposicionar(){
	int x=RNG(1), y= RNG(1);
	if (x>0){
		x=RNG(640+20,0-20);	
		if (y>0){
			y=360+20;
		}else{
			y=0;		
		}
	}else{
		if (y>0){
			x=640+20;
		}else{
			x=0-35;
		}
		y=RNG(360+20,0-20);
	}
	spr.setPosition(x,y);
	
}
/*void asteroide::cambiar_objetivo(){
	objetivo.x=RNG(640+64,0-64);
	objetivo.y=RNG(360+36,0-36);
}*/
void asteroide::cambiar_objetivo(){
	int x=RNG(1), y= RNG(1);
	if (x>0){
		x=RNG(640+35,0-35);	
		if (y>0){
			y=360+35;
		}else{
			y=0-35;		
		}
	}else{
		if (y>0){
			x=640+35;
		}else{
			x=0-35;
		}
		y=RNG(360+35,0-35);
	}
	objetivo.x=x;
	objetivo.y=y;
}
void asteroide::actualizar(){
	Vector2f aux=spr.getPosition();
	aux.x=aux.x;
	aux.y=aux.y;
	Vector2f direccion= (objetivo-aux);
	normal_v(direccion);
	spr.move(direccion.x*speed,direccion.y*speed);	
}
void asteroide::dibujar(RenderWindow &win){
	win.draw(spr);
}
