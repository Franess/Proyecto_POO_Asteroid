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
	//valores fisicos
	float magnitud;						//magnitud escalar del valor de la velocidad
	Vector2f velocidad;					//vector direccion*MAGNITUD del asteroide
	float size;							//valor de covercion 1=20 pixeles, tambien hace de valor para masa 
	float radio;
public:
	asteroide(Texture *tex_asteroide, int id_num);	//shared_ptr es un puntero inteligente
	void actualizar();								//mueve el ast al objetivo
	void dibujar(RenderWindow &win);	
	
	void cambiar_objetivo();
	void reposicionar();
	void set_direccion();
	void r_size();
	void set_velocidad(Vector2f new_v);
	void set_posicion(Vector2f v);
	
	float get_rad();
	float get_size();
	int get_id();
	Vector2f get_posicion();
	Vector2f get_velocidad();
};

#endif

