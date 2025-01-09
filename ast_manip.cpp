#include "ast_manip.h"
#include "asteroide.h"
#include <vector>
#include <iostream>
#include "Proyectil.h"
#include "tabla_de_puntos.h"
using namespace std;


void spawn (vector<asteroide> &a, Texture* tex){
	if (a.size()<50){
		int id= a.size();
		a.push_back(asteroide(tex,id));
		a[a.size()-1].r_size();
		a[a.size()-1].cambiar_objetivo();
		a[a.size()-1].reposicionar();
		a[a.size()-1].set_direccion();
		
	}
}
void respawn(vector<asteroide> &a){
	
	for(int i=0;i<a.size();i++) { 
		float limites = a[i].get_size()*11;
		if ( (a[i].get_posicion()> Vector2f(640+limites,360+limites))or(Vector2f(0-limites,0-limites)>a[i].get_posicion()) ){
			a[i].r_size();
			a[i].cambiar_objetivo();
			a[i].reposicionar();
			a[i].set_direccion();
			
		}
	}
}

	void colision(vector<asteroide> &v){
		float e=0.90;
		for(int i=0;i<v.size();i++) { 
			for(int j=i+1;j<v.size();j++) { 
				asteroide a=v[i],b=v[j];
				Vector2f aux= a.get_posicion()-b.get_posicion();
				if (sqrt(aux.x*aux.x+aux.y*aux.y)<a.get_rad()+b.get_rad()){
					
					Vector2f Vx=a.get_velocidad()-b.get_velocidad();
					Vector2f Px=a.get_posicion()-b.get_posicion();
					Vector2f norm=normal_v(Px);
					float factor_m=(((1+e)*b.get_size())/(a.get_size()+b.get_size()));
					Vector2f vf_A=a.get_velocidad()-factor_m*producto_escalar(Vx,norm)*norm;
					
					Vx=b.get_velocidad()-a.get_velocidad();
					Px=b.get_posicion()-a.get_posicion();
					norm=normal_v(Px);
					factor_m=(((1+e)*a.get_size())/(a.get_size()+b.get_size()));
					Vector2f vf_B=b.get_velocidad()-factor_m*producto_escalar(Vx,norm)*norm;
					
					v[i].set_velocidad(vf_A);
					v[j].set_velocidad(vf_B);
					//detalles de la formula en header
					
					float solapamiento= sqrt(aux.x*aux.x+aux.y*aux.y)-(a.get_rad()+b.get_rad());
					Vector2f correccion= norm*(solapamiento/2);
					v[i].set_posicion(v[i].get_posicion()+correccion*(v[i].get_size()/(v[i].get_size()+v[j].get_size())));
					v[j].set_posicion(v[j].get_posicion()-correccion*(v[j].get_size()/(v[i].get_size()+v[j].get_size())));
					//un simple reajuste de posicion que calcula el solapamiento de asteroides y mueve los asteroides en la direccion correspondiente mediante norm
					
				}
			}
		}
	}
	void destruir (vector<asteroide> &ast,  vector<Proyectil> &pro, tabla_de_puntos &tabla){
		for(int i=0;i<pro.size();i++) { 
			for(int j=0;j<ast.size();j++) {
				asteroide a= ast[j];
				Proyectil p= pro[i];
				Vector2f aux= a.get_posicion()-p.obtenerPosicion();
				if (sqrt( aux.x*aux.x + aux.y*aux.y )<(a.get_rad()+3.5)){
					ast[j].disminuir_hp(100);
					if (ast[j].get_hp()<0){
						tabla.actualizar_puntos_j(static_cast<int>(ast[j].get_size()*100));
						ast[j].r_size();
						ast[j].cambiar_objetivo();
						ast[j].reposicionar();
						ast[j].set_direccion();
					}
					pro.erase(pro.begin()+i);
					
					
					
				}
			}
		}
		
	}
	
