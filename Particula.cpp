#include "Particula.h"

Particula::Particula(float r, sf::Vector2f pos):m_radio(r)
{
	m_particula.setRadius(m_radio);
	m_particula.setOrigin(m_radio,m_radio);
	sf::Color aux(255,255,255,255);
	m_particula.setFillColor(aux);
	m_color = aux;
	m_particula.setPosition(pos);
	
}
void Particula::establecerPosicion(sf::Vector2f vec_posicion)
{
	m_particula.setPosition(vec_posicion);
}
void Particula::establecerRadio(float radio)
{
	m_radio=radio;
	m_particula.setRadius(m_radio);
}
void Particula::establecerVelocidad(sf::Vector2f vec_velocidad)
{
	m_velocidad = vec_velocidad;
}
void Particula::establecerColor(sf::Color c)
{
	m_color=c;
	m_color.a=m_transparencia;
	m_particula.setFillColor(m_color);
}
sf::Vector2f Particula::obtenerPosicion()const
{
	return m_particula.getPosition();
}
float Particula::obtenerRadio()const
{
	return m_radio;
}
sf::Vector2f Particula::obtenerVelocidad()const
{
	return m_velocidad;
}
void Particula::actualizar()
{
	m_particula.setFillColor(m_color);
	m_particula.move(m_velocidad);
}
void Particula::dibujar(sf::RenderWindow &win)
{
	win.draw(m_particula);
}
void Particula::marcarTiempo()
{
	m_tiempo = m_reloj.restart();
}
sf::Time Particula::obtenerTiempo()
{
	return m_reloj.getElapsedTime();
}
void Particula::cambiarTransparencia(float transp)
{
	m_transparencia=transp;
}
void Particula::aumentarTransparencia(float cant)
{
	if(m_transparencia<255)
	{
		m_transparencia+=cant;
		m_color.a=m_transparencia;
	}
}
void Particula::disminuirTransparencia(float cant)
{
	if(m_transparencia>0)
	{
		m_transparencia-=cant;
		m_color.a=m_transparencia;
	}
}
void Particula::establecerRotacion(int grados)
{
	m_particula.setRotation(grados);
}
float Particula::obtenerRotacion()const
{
	return m_particula.getRotation();
}
