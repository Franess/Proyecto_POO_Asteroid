#include "EscenaArchivos.h"
#include <stdexcept>
using namespace std;

EscenaArchivos::EscenaArchivos(int selector_escenaSig)
{
	m_fuente.loadFromFile("SixtyfourConvergence-Regular-VariableFont_BLED,SCAN,XELA,YELA.ttf");
	m_tituloPantalla.setFont(m_fuente);
	m_tituloPantalla.setString("Regenerar archivos");
	m_tituloPantalla.setCharacterSize(20);
	m_tituloPantalla.setScale(0.5,1);
	auto info_texto = m_tituloPantalla.getLocalBounds();
	m_tituloPantalla.setOrigin(info_texto.width/2,info_texto.height/2);
	m_tituloPantalla.setPosition(320,10);
	
	m_seccionTitulo.setSize(sf::Vector2f(640,30));
	m_seccionTitulo.setOutlineColor({255,255,255});
	m_seccionTitulo.setOutlineThickness(2);
	m_seccionTitulo.setFillColor({0,0,0,0});
	m_seccionTitulo.setOrigin(0,0);
	m_seccionTitulo.setPosition(0,0);
}
void EscenaArchivos::Actualizar(Juego & j) 
{
	
}

void EscenaArchivos::Dibujar(sf::RenderWindow & win)
{
	win.draw(m_tituloPantalla);
	win.draw(m_seccionTitulo);
}

void EscenaArchivos::ProcesarEvento(Juego & j, sf::Event e) 
{
	
}
EscenaArchivos::~EscenaArchivos()
{
	
}
