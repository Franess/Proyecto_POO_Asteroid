#include "Boton.h"

Boton::Boton(string texto_boton, sf::Font *fuente, int tamanio_letras)
{
	m_texto.setFont(*fuente);
	m_texto.setCharacterSize(tamanio_letras);
	m_texto.setString(texto_boton);
	m_texto.setFillColor({255,255,255});
	//Se calcula el orgien al centro del rectangulo, en base a las dimensiones del texto. No se puede modificar desde un metodo.
	sf::Rect<float> info_BordesTexto = m_texto.getGlobalBounds();
	float pos_origX = (info_BordesTexto.width)/2;
	float pos_origY = (info_BordesTexto.height)/2;
	m_texto.setOrigin(pos_origX,pos_origY);
	
	sf::Vector2f tamanio_borde(info_BordesTexto.width+4,info_BordesTexto.height+15);
	m_tamanioBorde = tamanio_borde;
	m_borde.setSize(tamanio_borde);
	m_borde.setOrigin(pos_origX,pos_origY);
	m_borde.setFillColor({0,0,0,0});
	m_borde.setOutlineThickness(2);
	m_borde.setOutlineColor({255,255,255});
}

Boton::~Boton()
{
	
}

void Boton::actualizar()
{
	colorFondo({0,0,0,0});
	sf::Rect<float> info_BordesTexto = m_texto.getGlobalBounds();
	float pos_origX = (info_BordesTexto.width)/2;
	float pos_origY = (info_BordesTexto.height)/2;
	m_texto.setOrigin(pos_origX,pos_origY);
	
	sf::Vector2f tamanio_borde(info_BordesTexto.width+4,info_BordesTexto.height+15);
	m_tamanioBorde = tamanio_borde;
	m_borde.setSize(tamanio_borde);
	m_borde.setOrigin(pos_origX,pos_origY);
}
void Boton::dibujar(sf::RenderWindow &win)
{
	win.draw(m_texto);
	win.draw(m_borde);
}

void Boton::establecerPosicion(float x, float y)
{
	m_texto.setPosition(x,y);
	m_borde.setPosition(x,y);
}
void Boton::establecerTexto(string nuevo_texto)
{
	m_texto.setString(nuevo_texto);
}
void Boton::establecertamanioFuente(int nuevo_tamanio)
{
	m_texto.setCharacterSize(nuevo_tamanio);
}
void Boton::establecerColorTexto(sf::Color c)
{
	m_texto.setFillColor(c);
}
void Boton::establecerGrosorBordes(float th)
{
	m_borde.setOutlineThickness(th);
}
void Boton::establecerColorBordes(sf::Color c)
{
	m_borde.setOutlineColor(c);
}
void Boton::colorFondo(sf::Color c)
{
	m_borde.setFillColor(c);
}
void Boton::escalado(float multi_x, float multi_y)
{
	m_texto.setScale(multi_x,multi_y);
	m_borde.setScale(multi_x,multi_y);
}
sf::Vector2f Boton::obtenerPunto(int i)const
{
	return m_borde.getPoint(i);
}
sf::Vector2f Boton::obtenerPosicion()const
{
	return m_borde.getPosition();
}
float Boton::obtenerAnchoBorde()const
{
	sf::Rect<float> info_BordesTexto = m_borde.getGlobalBounds();
	return info_BordesTexto.width;
}
float Boton::obtenerAltoBorde()const
{
	sf::Rect<float> info_BordesTexto = m_borde.getGlobalBounds();
	return info_BordesTexto.height;
}

sf::Vector2f Boton::obtenerVectorPosRelativo()
{
	sf::Rect<float> info_BordesTexto = m_borde.getGlobalBounds();
	sf::Vector2f aux(info_BordesTexto.left,info_BordesTexto.top);
	return aux;
}
