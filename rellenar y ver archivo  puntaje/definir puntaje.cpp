#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;
struct puntaje{
	int puntos;
	char nombre[16];
};
int main() {
	vector<string> s ={
		"Dios.asm",
		"jhon++",
		"aGente_P.T",
		"cefi",
		"BAD_Ceju",
		"Brass_Sniper",
		"Jalape�o417",
		"Mayy_23",	
		"Fran.cpp",	
		"Glass.h"	
	};
	vector<int> n={
		100000,
		50000,	
		35000,
		25000,
		20000,
		10000,
		4000,
		2000,
		1500,
		500
	};
	vector<puntaje> p;
	puntaje aux;
	for(int i=0;i<10;i++) { 
		strcpy(aux.nombre,s[i].c_str());
		aux.puntos=n[i];
		p.push_back(aux);
	}
	fstream archi("puntaje.poo", ios::binary|ios::trunc|ios::out);
	if (!archi.is_open()){
		cout<<"error al abrir el archivo"<<endl;
	}
	for(int i=0;i<10;i++) { 
		aux=p[i];
		archi.write(reinterpret_cast<const char*>(&aux), sizeof(puntaje));
	}
	archi.close();
	return 0;
}

