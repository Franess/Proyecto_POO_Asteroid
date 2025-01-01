#include "tabla_de_puntos.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

tabla_de_puntos::tabla_de_puntos(string nombre_archi) {
	archivo_puntos=nombre_archi;
	puntos_jugador.puntos=0;
}

void tabla_de_puntos::actualizar_archivo_puntaje(){
	fstream archi(archivo_puntos, ios::binary|ios::in|ios::out);
	archi.seekp(0, ios::beg);
	if (!archi.is_open()){
		cout<<"error al abrir el archivo"<<endl;
		return;
	}
	vector<puntaje> v(10);
	puntaje aux;
	for(int i=0;i<10;i++) {
		archi.read(reinterpret_cast<char*>(&aux),sizeof(puntaje));
		v[i]=aux;
	}
	for(int i=0;i<10;i++) { 
		if (puntos_jugador.puntos>v[i].puntos){
			for(int j=v.size()-1;j>i;j--) { 
				v[j]=v[j-1];
			}
			v[i]=puntos_jugador;
		}
	}
	for(int i=0;i<10;i++) { 
		aux=v[i];
		archi.write(reinterpret_cast<const char*>(&aux), sizeof(puntaje));
	}
	archi.close();
}
	
void tabla_de_puntos::actualizar_puntos_j(int puntos_a_sumar){
	puntos_jugador.puntos+=puntos_a_sumar;
}
