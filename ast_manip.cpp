#include "ast_manip.h"
#include "asteroide.h"
#include <vector>
using namespace std;


void spawn (vector<asteroide> &a, Texture* tex){
	if (a.size()<15){
		a.push_back(asteroide(tex));
		a[a.size()-1].r_size();
		a[a.size()-1].r_speed();
		
		a[a.size()-1].cambiar_objetivo();
		a[a.size()-1].reposicionar();
	}
}
void respawn(vector<asteroide> &a){
	for(int i=0;i<a.size();i++) { 
		if ( (a[i].posicion()> Vector2f(640+10,360+10))or(Vector2f(0-10,0-10)>a[i].posicion()) ){
			a[i].r_size();
			a[i].r_speed();
			
			a[i].cambiar_objetivo();
			a[i].reposicionar();
			
		}
	}
}
	

