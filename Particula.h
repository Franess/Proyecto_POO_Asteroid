#ifndef PARTICULA_H
#define PARTICULA_H
#include <SFML/Graphics.hpp>

class Particula {
public:
	Particula(float r, sf::Vector2f pos);
	void establecerPosicion(sf::Vector2f vec_posicion);
	void establecerRadio(float radio);
	void establecerVelocidad(sf::Vector2f vec_velocidad);
	void establecerColor(sf::Color c);
	sf::Vector2f obtenerPosicion()const;
	float obtenerRadio()const;
	sf::Vector2f obtenerVelocidad()const;
	void actualizar();
	void dibujar(sf::RenderWindow &win);
	void marcarTiempo();
	sf::Time obtenerTiempo();
	void cambiarTransparencia(float transp);
	void aumentarTransparencia(float cant);
	void disminuirTransparencia(float cant);
	void establecerRotacion(int grados);
	float obtenerRotacion()const;
private:
	sf::CircleShape m_particula;
	sf::Vector2f m_velocidad;
	sf::Color m_color;
	float m_transparencia=255;
	float m_radio;
	sf::Clock m_reloj;
	sf::Time m_tiempo;
};

#endif

