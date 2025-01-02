#ifndef NAVE_H
#define NAVE_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Settings.h"
#include <vector>
#include <SFML/Window/Keyboard.hpp>
using namespace std;
using namespace sf;
class Nave{
public:
	Nave(float r, int p,  Settings &s);
	void actualizar();
	void dibujar(RenderWindow &win);
private:
	CircleShape m_nave;
	vector<Keyboard::Key> m_teclas;
};
#endif

