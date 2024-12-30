#include "Settings.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

Settings::Settings() {
	fstream archi("Set_Controls.txt");
	if(!archi.is_open()){throw runtime_error("No se pudo abrir el archivo");}
	vector<string> aux; string s;
	while(getline(archi,s)){
		if(s.find_first_of('#',0)){
			aux.push_back(s);
		}
	}
	archi.close();
	for(string &x:aux){
		char p[2];
		strcpy(p,x.c_str());
		int y = static_cast<int>(p[0])-65; 
		teclas_nave.push_back(static_cast<Keyboard::Key>(y));
	}
}
vector<Keyboard::Key> Settings::obtenerTeclas() const{
	return teclas_nave;
}

