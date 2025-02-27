#ifndef BOTON_H
#define BOTON_H
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class Boton 
{
public:
	Boton() = default;
	Boton(string texto_boton, sf::Font *fuente, int tamanio_letras);
	void establecerPosicion(float x, float y);
	void establecerTexto(string nuevo_texto);
	void establecertamanioFuente(int nuevo_tamanio);
	void establecerColorTexto(sf::Color c);
	void establecerGrosorBordes(float th);
	void establecerColorBordes(sf::Color c);
	void colorFondo(sf::Color c);
	void escalado(float multi_x, float multi_y);
	sf::Vector2f obtenerPunto(int i)const;
	sf::Vector2f obtenerPosicion()const;
	float obtenerAnchoBorde()const;
	float obtenerAltoBorde()const;
	sf::Vector2f obtenerVectorPosRelativo();
	
	
	void actualizar();
	void dibujar(sf::RenderWindow &win);
	~Boton();
private:
	sf::Text m_texto;
	sf::RectangleShape m_borde; //Es para hacer un recuadro que rodee al texto
	sf::Vector2f m_tamanioBorde;
	vector<float> m_esclares = {1.f,1.f};
};

#endif

