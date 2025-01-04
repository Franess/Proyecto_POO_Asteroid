#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Proyectil {
public:
	Proyectil();
	void actualizar();
	void dibujar(RenderWindow &win);
private:
	CircleShape m_formaProye;
};

#endif

