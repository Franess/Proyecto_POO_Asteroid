#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Proyectil {
public:
	Proyectil(Vector2f set_p, float nave_rotation);
	void actualizar();
	void dibujar(RenderWindow &win);
	Vector2f obtenerPosicion()const;
private:
	CircleShape m_formaProye;
};

#endif

