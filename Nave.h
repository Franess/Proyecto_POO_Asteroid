#ifndef NAVE_H
#define NAVE_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class Nave{
public:
	Nave(float r, int p);
	void actualizar();
	void dibujar(RenderWindow &win);
private:
	CircleShape m_nave;			
};
#endif

