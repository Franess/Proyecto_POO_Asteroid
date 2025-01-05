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
	magnitud=1;
	size=1;
	spr.setScale(size,size);
	radio=size*10;
	spr.setOrigin(size*10,size*10);
}

Vector2f asteroide::get_posicion(){
	return spr.getPosition();
}
float asteroide::get_size(){
	return size;
}
int asteroide::get_id(){
	return ast_id;
}
float asteroide::get_rad(){
	return radio;
}
Vector2f asteroide::get_velocidad(){
	return velocidad;
}


void asteroide::r_size(){
	size=static_cast<float>(RNG(300,50))/100.0;
	spr.setScale(size,size);
	ast_hp=size*10;
	radio=size*9;
	//cout<<"size "<<size<<" hp "<<ast_hp<<endl;
	auto limites=spr.getLocalBounds();
	spr.setOrigin(limites.width/2,limites.height/2);
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
void asteroide::set_direccion(){
	magnitud=static_cast<float>(RNG(300,25)/100.0);
	Vector2f aux=spr.getPosition();
	direccion=(objetivo-aux);
	normal_v(direccion);
	velocidad=(direccion*magnitud);	
}
void asteroide::set_posicion(Vector2f v){
	spr.setPosition(v);
}
void asteroide::set_velocidad(Vector2f new_v){
	velocidad=new_v;
}

void asteroide::actualizar(){
	spr.move(velocidad);
}
void asteroide::dibujar(RenderWindow &win){
	win.draw(spr);
}


