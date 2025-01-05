#ifndef MANEJO_AST_H
#define MANEJO_AST_H
#include "asteroide.h"
#include "complemento_v.h"
#include <vector>
using namespace std;

void spawn (vector<asteroide> &a, Texture* tex);
void respawn(vector<asteroide> &a);
void destruir (vector<asteroide> &a, int id=-1);

void colision(vector<asteroide> &v);	
/* 
calcula una colision elastica total (sin perdidas de energia)
la funcion utilizada es:
	vf_A= vi_A - factor_m * (Vx · norma); 
["·" refiere a una proyeccion de vectores /producto escalar entre vectores.]
donde:
	factor_m es el coeficiente de variabilidad de direccion en base a la diferencia relativa de masas
		factor_m= (2 * masa_A / (masa_A+masa_B));

	Vx es la diferencia de velocidades A B (vector relativo de velocidad);
	
	norma es el vector normal de colision (apuntan desde el centro del objeto a hacia el centro del objeto b)
	norma= vector_normalizado(poscicion_a-posicion_b);
	
[ver complemento_v para formulas de normalicacion y producto escalar entre vectores]
	
*/
#endif

