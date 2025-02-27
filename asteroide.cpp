#include "asteroide.h"
#include "rng.h"
#include <cmath>
#include "complemento_v.h"

#include <iostream>
using namespace std;
asteroide::asteroide(Texture *tex_asteroide,int id_num) {
	//tex=tex_asteroide;
	//spr.setTexture(*tex);
	ast_id=id_num;
	spr.setTexture(*tex_asteroide);
	magnitud=1;
	size=1;
	spr.setScale(size,size);
	radio=(size*9)+(0.25*size/3);
	spr.setOrigin(size*10,size*10);
	ast_color=Color(255,255,255,255);
}

Vector2f asteroide::get_posicion(){
	return spr.getPosition();
}
float asteroide::get_size(){
	return size;
}
/*
int asteroide::get_id(){
	return ast_id;
}
*/
float asteroide::get_rad(){
	return radio;
}
Vector2f asteroide::get_velocidad(){
	return velocidad;
}
int asteroide::get_hp(){
	return ast_hp;
}

void asteroide::disminuir_hp(int danio){
	ast_hp-=danio;
}

void asteroide::r_size(float var){
	size=static_cast<float>(RNG(300,50))/100.0;
	spr.setScale(size*var,size*var);
	ast_hp=static_cast<int>(size*100);
	radio=(size*9)*var+(0.25*size/3)*var;
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
void asteroide::set_direccion(float var){
	magnitud=static_cast<float>((RNG(250,50)/100.0)*var);
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
	if((ast_color.g<255)&&(ast_color.g>0)){
		ast_color=Color(255,ast_color.g+20,ast_color.b+20);
		spr.setColor(Color(ast_color.r,ast_color.g,ast_color.b));
	}
	spr.move(velocidad);
}
void asteroide::dibujar(RenderWindow &win){
	win.draw(spr);
}
void asteroide::set_color(int r, int g, int b, int a){
	ast_color=Color(r,g,b,a);
	spr.setColor(ast_color);
}

