#include "AsteroideExplosion.h"
#include <cmath>
#include "Particula.h"
#include "rng.h"
using namespace std;
sf::Vector2f generarVectorVelocidad(Particula &p){
	float radianes = p.obtenerRotacion()*M_PI/180;
	float rand_velocidad = -log(1.0/(RNG(149+1)));
	return sf::Vector2f(rand_velocidad*cos(radianes),rand_velocidad*sin(radianes));
}

AsteroideExplosion::AsteroideExplosion(asteroide &a) {
	int area_asteroide = std::pow(a.get_rad(),2)*M_PI;
	float cant_asteroides = static_cast<int>(area_asteroide*(50.f/100));
	for(int i=0;i<cant_asteroides;i++)
	{ 
		Particula parti(1,a.get_posicion());
		parti.establecerRotacion(RNG(360,1));
		sf::Vector2f vec_auxiliar = generarVectorVelocidad(parti);
		parti.establecerVelocidad(vec_auxiliar);
		m_vecParticulas.push_back(parti);
	}
}

void AsteroideExplosion::actualizar() 
{
	for(Particula &x:m_vecParticulas)
	{
		x.disminuirTransparencia((17.f/2));
		x.actualizar();
	}
}

void AsteroideExplosion::dibujar (sf::RenderWindow & win) 
{
	for(Particula &x:m_vecParticulas)
	{
		x.dibujar(win);
	}
}
int AsteroideExplosion::obtenerCantParticulas()const
{
	return m_vecParticulas.size();
}
sf::Time AsteroideExplosion::obtenerTiempo()const
{
	return m_reloj.getElapsedTime();
}
void AsteroideExplosion::marcarTiempo()
{
	m_tiempo = m_reloj.restart();
}
