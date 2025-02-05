#include "tabla_de_puntos.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

tabla_de_puntos::tabla_de_puntos() {
	archivo_puntos="puntaje.poo";
	puntos_jugador.puntos=0;
}
void tabla_de_puntos::actualizar_archivo_puntaje(){
	fstream archi(archivo_puntos, ios::binary|ios::in|ios::out);
	if (!archi.is_open()){
		cout<<"error al abrir el archivo"<<endl;
		return;
	}
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
			break;
		}
	}
	for(int i=0;i<10;i++) { 
		aux=v[i];
		archi.seekp(i*sizeof(puntaje),ios::beg);
		archi.write(reinterpret_cast<const char*>(&aux), sizeof(puntaje));
	}
	archi.close();
}
	
void tabla_de_puntos::actualizar_puntos_j(int puntos_a_sumar){
	puntos_jugador.puntos+=puntos_a_sumar;
}
void tabla_de_puntos::recibir_nombre_j(string nombre_j){
	strcpy(puntos_jugador.nombre,nombre_j.c_str());	//sizeof se utiliza para evitar la sobreescritura en la memoria
}

int tabla_de_puntos::get_puntos(){
	return puntos_jugador.puntos;
}

vector<puntaje> tabla_de_puntos::cargar_lista(){
	fstream archi(archivo_puntos, ios::binary|ios::in);
	if (!archi.is_open()){
		cout<<"error al abrir el archivo"<<endl;
	}
	archi.seekp(0, ios::beg);
	vector<puntaje> v(10);
	puntaje aux;
	for(int i=0;i<10;i++) {
		archi.read(reinterpret_cast<char*>(&aux),sizeof(puntaje));
		v[i]=aux;
	}
	return v;
}
