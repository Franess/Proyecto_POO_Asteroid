#ifndef MANEJO_AST_H
#define MANEJO_AST_H
#include "asteroide.h"
#include "complemento_v.h"
#include <vector>
#include "Proyectil.h"
#include "tabla_de_puntos.h"
#include "AsteroideExplosion.h"
#include <SFML/Audio.hpp>

using namespace std;
void spawn (vector<asteroide> &a, Texture* tex,float var=1);
void respawn(vector<asteroide> &a,float var=1);
void indicador_d(vector<asteroide> &ast);
bool destruir (vector<asteroide> &ast,  vector<Proyectil> &pro, vector<AsteroideExplosion> &exp, tabla_de_puntos &tabla);
void colision(vector<asteroide> &v);	

/* 
calcula una colision elastica total (sin perdidas de energia)
la funcion utilizada es:
	vf_A= vi_A - factor_m * (Vx � norma); 
["�" refiere a una proyeccion de vectores /producto escalar entre vectores.]
donde:
	factor_m es el coeficiente de variabilidad de direccion en base a la diferencia relativa de masas
		factor_m= (1+e * masa_B / (masa_A+masa_B));
	e es el coeficiente de elasticidad del material (1 completamente elastican / 0 completamente inelastica) 
	Vx es la diferencia de velocidades A B (vector relativo de velocidad);
	
	norma es el vector normal de colision (apuntan desde el centro del objeto a hacia el centro del objeto b)
	norma= vector_normalizado(poscicion_a-posicion_b);
[todos los calculos estan hechos en base a A, simplemente invertir a,b y b,a para calcular para B]
[ver complemento_v para formulas de normalicacion y producto escalar entre vectores]
	
*/
#endif

