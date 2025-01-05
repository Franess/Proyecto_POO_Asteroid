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
//void colision(asteroide &a, asteroide &b);
	
#endif

