#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class asteroide {
	Texture tex;
	Sprite spr;
	Vector2f objetivo;
	int speed;
public:
	asteroide();
	void cambiar_objetivo();
	void actualizar();
	void dibujar(RenderWindow &win);
	void reposicionar();
	Vector2f posicion();
};

#endif

