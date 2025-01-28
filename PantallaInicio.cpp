#include "PantallaInicio.h"
#include <algorithm>
#include "OnePlayer.h"
#include "Settings.h"
using namespace std;

bool calculo_sobreposicion(sf::Vector2f pos_puntero, Boton &b,float ex, float ey)
{
	sf::Vector2f pos_actualBoton = b.obtenerVectorPosRelativo();
	bool zona_x = (pos_actualBoton.x)*ex <=pos_puntero.x&& pos_puntero.x<=(pos_actualBoton.x+b.obtenerAnchoBorde())*ex;
	bool zona_y = (pos_actualBoton.y)*ey<=pos_puntero.y && pos_puntero.y<=(pos_actualBoton.y+b.obtenerAltoBorde())*ey;
	if(zona_x && zona_y) return true;
	else return false;
}

vector<float> actualizarEscalares(sf::RenderWindow &w)
{
	vector<float> v_aux;
	sf::Vector2u aux = w.getSize();
	v_aux.push_back(static_cast<float>(aux.x)/640);
	v_aux.push_back(static_cast<float>(aux.y)/360);
	return v_aux;
}

PantallaInicio::PantallaInicio() 
{
	bool estado_fuente = m_fuente.loadFromFile("Roboto_Condensed-Bold.ttf");
	bool estado_textura = m_textura.loadFromFile("asteroide.png");
	bool estado_imgFondo = m_imgFondo.loadFromFile("fondoPantallaInicio.jpg");
	if(!estado_imgFondo) throw runtime_error("No se encuentra el fondo fondoPantallaInicio.jpg");
	if(!estado_fuente) throw runtime_error("No se encuentra la fuente Roboto_Condensed-Bold.ttf");
	if(!estado_textura) throw runtime_error("No se encuentra la textura asteroide.png");
	m_imagenAsteroide.setTexture(m_textura);
	m_comienzoNombre.setFont(m_fuente);
	m_finalNombre.setFont(m_fuente);
	m_mensajeSalir.setFont(m_fuente);
	
	m_mensajeSalir.setCharacterSize(10);
	m_comienzoNombre.setCharacterSize(50);
	m_finalNombre.setCharacterSize(50);
	m_mensajeSalir.setFillColor({255,255,255});
	m_comienzoNombre.setFillColor({255,255,255});
	m_finalNombre.setFillColor({255,255,255});
	m_mensajeSalir.setString("<Presione la tecla 'esc' para salir>");
	m_comienzoNombre.setString("Aster");
	m_finalNombre.setString("ids");
	m_mensajeSalir.setOrigin(0,0);
	m_comienzoNombre.setOrigin(0,0);
	m_finalNombre.setOrigin(0,0);
	m_mensajeSalir.setPosition(243,345);
	m_comienzoNombre.setPosition(205,60);
	m_finalNombre.setPosition(365,60);
	
	
	m_imagenAsteroide.setScale(2.f,2.f);
	m_imagenAsteroide.setOrigin(0,0);
	m_imagenAsteroide.setPosition(340,95);
	sf::Rect<float> aux_Bordesimg = m_imagenAsteroide.getLocalBounds();
	m_imagenAsteroide.setOrigin((aux_Bordesimg.height)/2,(aux_Bordesimg.height)/2);
	
	m_sprFondo.setTexture(m_imgFondo);
	m_sprFondo.setOrigin(0,0);
	m_sprFondo.setPosition(0,0);
	
	Boton nuevo_boton("Jugar",&m_fuente,30);
	nuevo_boton.establecerPosicion(320,220);
	vec_botones.push_back(nuevo_boton);
	Boton nuevo_boton1("Puntaje",&m_fuente,30);
	nuevo_boton1.establecerPosicion(320,280);
	vec_botones.push_back(nuevo_boton1);
	
	
}

void PantallaInicio::Actualizar (Juego & j)
{
	m_imagenAsteroide.rotate(3);
}
void PantallaInicio::Dibujar (sf::RenderWindow & win) {
	win.clear({0,0,0});
	m_escalas = actualizarEscalares(win);
	win.draw(m_sprFondo);
	win.draw(m_comienzoNombre);
	win.draw(m_finalNombre);
	win.draw(m_imagenAsteroide);
	win.draw(m_mensajeSalir);
	for(Boton &x:vec_botones){
		x.dibujar(win);
	}
}
void PantallaInicio::ProcesarEvento(Juego &j, sf::Event e)
{
	if(e.type == sf::Event::MouseMoved)
	{
		sf::Vector2f pos_mouse(e.mouseMove.x,e.mouseMove.y);
		for(Boton &x:vec_botones){
			if(calculo_sobreposicion(pos_mouse,x,m_escalas[0],m_escalas[1]))
			{ 
				x.colorFondo({190,255,250,50});
			}
			else x.colorFondo({0,0,0,0});
		}
	}
	if(e.type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2f pos_mouse(e.mouseButton.x,e.mouseButton.y);
		if(calculo_sobreposicion(pos_mouse,vec_botones[0],m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
		{
			Settings s;
			j.CambiarEscena(new OnePlayer(s));
		}
	}
	if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Escape)
	{
		j.terminar();
	}
}
PantallaInicio::~PantallaInicio()
{
	
}
