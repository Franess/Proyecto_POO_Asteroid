#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "asteroide.h"
using namespace std;
using namespace sf;
class asteroide{
	//valores y datos caracteristicos
	Texture* tex;
	Sprite spr;
	Vector2f objetivo;					//punto hacia el que se dirige el ast
	Vector2f direccion;
	int ast_hp;
	int ast_id;
	Color ast_color;

	//valores fisicos
	float magnitud;						//magnitud escalar del valor de la velocidad
	Vector2f velocidad;					//vector direccion*MAGNITUD del asteroide
	float size;							//valor de covercion 1=20 pixeles, tambien hace de valor para masa 
	float radio;
public:
	asteroide(Texture *tex_asteroide, int id_num);	//shared_ptr es un puntero inteligente
	void actualizar();								//mueve el ast al objetivo
	void dibujar(RenderWindow &win);	
	
	void disminuir_hp(int danio);
	void cambiar_objetivo();
	void reposicionar();
	void set_direccion(float var=1);
	void r_size(float=1);
	void set_velocidad(Vector2f new_v);
	void set_posicion(Vector2f v);
	//void set_id();
	void set_color(int r=255, int g=255, int b=255, int a=255);
	
	float get_rad();
	float get_size();
	//int get_id();
	int get_hp();
	Vector2f get_posicion();
	Vector2f get_velocidad();
};

#endif

