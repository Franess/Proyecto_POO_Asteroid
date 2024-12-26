#include "Nave.h"
using namespace std;

Nave::Nave(float r, int p) {
	CircleShape o_nave(r,p);
	m_nave=o_nave;
	m_nave.setOrigin(40.f,40.f);
	m_nave.setPosition(100,100);
	m_nave.setFillColor({239,254,0});
}
void Nave::actualizar()
{
	m_nave.move(1,0);
	m_nave.rotate(2);
}
void Nave::dibujar(RenderWindow &win)
{
	win.draw(m_nave);
}
