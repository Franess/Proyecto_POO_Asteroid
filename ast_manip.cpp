#include "ast_manip.h"
#include "asteroide.h"
#include <vector>
using namespace std;


void spawn (vector<asteroide> &a, Texture* tex){
	if (a.size()<15){
		int id= a.size()-1;
		a.push_back(asteroide(tex,id));
		a[a.size()-1].r_size();
		a[a.size()-1].r_speed();
		
		a[a.size()-1].cambiar_objetivo();
		a[a.size()-1].reposicionar();
	}
}
void respawn(vector<asteroide> &a){
	
	for(int i=0;i<a.size();i++) { 
		float limites = a[i].tell_size()*11;
		if ( (a[i].posicion()> Vector2f(640+limites,360+limites))or(Vector2f(0-limites,0-limites)>a[i].posicion()) ){
			a[i].r_size();
			a[i].r_speed();
			
			a[i].cambiar_objetivo();
			a[i].reposicionar();
			
		}
	}
}
	void destruir (vector<asteroide> &a, size_t id=-1){
		if(id!=-1){
			a[id].r_size();
			a[id].r_speed();
			a[id].cambiar_objetivo();
			a[id].reposicionar();
		}
	}

