#include "asteroide.h"
#include "rng.h"
#include <cmath>
#include "complemento_v.h"

#include <iostream>
using namespace std;
asteroide::asteroide(Texture *tex_asteroide,int id_num) {
	//tex=tex_asteroide;
	//spr.setTexture(*tex);
	spr.setTexture(*tex_asteroide);
	spr.setScale(1,1);
	speed=1;
	size=1;
	spr.setOrigin(size*10,size*10);
}

Vector2f asteroide::posicion(){
	return spr.getPosition();
}
float asteroide::tell_size(){
	return size;
}
int asteroide::tell_id(){
	return ast_id;
}
void asteroide::r_speed(){
	speed=static_cast<float>(RNG(150,25)/100.0);
}

void asteroide::r_size(){
	size=static_cast<float>(RNG(500,50))/100.0;
	spr.setScale(size,size);
	ast_hp=size*10;
	//cout<<"size "<<size<<" hp "<<ast_hp<<endl;
	auto limites=spr.getLocalBounds();
	spr.setOrigin(limites.width/2,limites.height/2);
	radio=limites.width/2;
}

void asteroide::reposicionar(){
	int x=RNG(1), y= RNG(1);
	if (x>0){
		x=RNG(640+size*20,0-size*20);	
		if (y>0){
			y=360+size*20;
		}else{
			y=0-size*20;		
		}
	}else{
		if (y>0){
			x=640+size*20;
		}else{
			x=0-size*20;
		}
		y=RNG(360+size*20,0-size*20);
	}
	spr.setPosition(x,y);
	
}

void asteroide::cambiar_objetivo(){
	int x=RNG(1), y= RNG(1);
	if (x>0){
		x=RNG(640+size*32,0-size*32);	
		if (y>0){
			y=360+size*32;
		}else{
			y=0-size*32;		
		}
	}else{
		if (y>0){
			x=640+size*32;
		}else{
			x=0-size*32;
		}
		y=RNG(360+size*32,0-size*32);
	}
	objetivo.x=x;
	objetivo.y=y;
}
void asteroide::actualizar(){
	Vector2f aux=spr.getPosition();
	Vector2f direccion= (objetivo-aux);
	normal_v(direccion);
	spr.move(direccion.x*speed,direccion.y*speed);	
}
void asteroide::dibujar(RenderWindow &win){
	win.draw(spr);
}
