#ifndef FUNCIONESBOTONES_H
#define FUNCIONESBOTONES_H
#include <SFML/Graphics.hpp>
#include "Boton.h"
#include <vector>
using namespace std;
bool calculo_sobreposicion(sf::Vector2f pos_puntero, Boton &b,float ex, float ey);	
vector<float> actualizarEscalares(sf::RenderWindow &w);
#endif
