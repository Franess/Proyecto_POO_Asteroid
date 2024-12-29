#include "asteroide.h"
#include "rng.h"
#include <cmath>
#include "normalizar.h"
using namespace std;
asteroide::asteroide() {
	tex.loadFromFile("asteroide.png");
	spr.setTexture(tex);
	spr.setOrigin(10,10);
	objetivo.x=RNG(640-64,0+64);
	objetivo.y=RNG(360-36,0+36);
}
void asteroide::reposicionar(){
	
	int x=RNG(1), y= RNG(1);
	if (x>0){
		x=RNG(670,-30);	
		if (y>0){
			y=390;
		}else{
			y=-30;		
		}
	}else{
		if (y>0){
			x=670;
		}
		y=RNG(390,-30);
	}
	spr.setPosition(x,y);
	
}
void asteroide::actualizar(){
	
	Vector2f direccion= objetivo-spr.getPosition();
	normal_v(direccion);
	spr.move(direccion.x*2,direccion.y*2);	
}
void asteroide::dibujar(RenderWindow &win){
	win.draw(spr);
}
