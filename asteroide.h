#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
using namespace std;
using namespace sf;
class asteroide{
	Texture* tex;
	Sprite spr;
	Vector2f objetivo;					//punto hacia el que se dirige el ast
	float speed;
	float size;							//valor de covercion 1=20 pixeles
public:
	asteroide(Texture *tex_asteroide);	//shared_ptr es un puntero inteligente
	void cambiar_objetivo();
	void actualizar();					//mueve el ast al objetivo
	void dibujar(RenderWindow &win);	
	void reposicionar();
	void r_speed();
	void r_size();
	Vector2f posicion();
};

#endif

