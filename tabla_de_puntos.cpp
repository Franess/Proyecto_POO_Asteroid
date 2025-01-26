#include "tabla_de_puntos.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

tabla_de_puntos::tabla_de_puntos(string nombre_archi) {
	archivo_puntos=nombre_archi;
	puntos_jugador.puntos=0;
}

void tabla_de_puntos::actualizar_archivo_puntaje(){
	fstream archi(archivo_puntos, ios::binary|ios::in|ios::out);
	if (!archi.is_open()){
		cout<<"error al abrir el archivo"<<endl;
		return;
	}
	
	archi.seekp(sizeof(puntos_jugador)*10,ios::beg);
	archi.read(reinterpret_cast<char*>(&puntos_jugador.puntos),sizeof(int));
	
	archi.seekp(0, ios::beg);
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
void tabla_de_puntos::recibir_nombre_j(string nombre_j){
	strncpy(puntos_jugador.nombre,nombre_j.c_str(),sizeof (nombre_j)-1);	//sizeof se utiliza para evitar la sobreescritura en la memoria
}

int tabla_de_puntos::get_puntos(){
	return puntos_jugador.puntos;
}

void tabla_de_puntos::guardado_temporal(){
	ofstream archi(archivo_puntos, ios::binary|ios::out|ios::app);
	archi.seekp(sizeof(puntos_jugador)*10,ios::beg);
	archi.write(reinterpret_cast<const char*>(&puntos_jugador.puntos),sizeof(int));
	archi.close();
};

