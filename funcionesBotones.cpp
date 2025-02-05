#include "funcionesBotones.h"
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
