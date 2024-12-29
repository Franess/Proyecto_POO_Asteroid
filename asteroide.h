#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class asteroide {
	Texture tex;
	Sprite spr;
public:
	asteroide();
	void actualizar();
	void dibujar(RenderWindow &win);
	void reposicionar();

};

#endif

