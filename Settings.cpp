#include "Settings.h"
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

Settings::Settings() {
	
	//Abre el archivo y guarda las lineas de texto de interes para el programa
	fstream archi("Set_Controls.txt",ios::in);
	if(!archi.is_open()){throw runtime_error("No se pudo abrir el archivo");}
	string s;
	while(getline(archi,s)){
		m_teclasCrudo.push_back(s);
		if(s.find_first_of('#',0)){
			m_stringsTeclas.push_back(s);
		}
	}
	archi.close();
}
vector<Keyboard::Key> Settings::obtenerControles() {
	vector<Keyboard::Key> teclas_nave;
	vector<string> ref_teclas = {
		"Space",
		"Enter",
		"Backspace",
		"Tab",
		"Flecha-Derecha",
		"Flecha-Izquierda",
		"Flecha-Arriba",
		"Flecha-Abajo"
	};
	//Son las teclas y sus referencias en string que no se pueden calcular con facilidad entre la relacion ascii y el mapa de valores para teclas de sfml
	vector<Keyboard::Key> teclas_sfml = {
		Keyboard::Space,
		Keyboard::Return,
		Keyboard::BackSpace,
		Keyboard::Tab,
		Keyboard::Right,
		Keyboard::Left,
		Keyboard::Up,
		Keyboard::Down
	};
	
	for(string &x:m_stringsTeclas){
		auto encontrar_Tecla = find(ref_teclas.begin(),ref_teclas.end(),x);
		
		if(encontrar_Tecla!=ref_teclas.end()){
			int posicion = encontrar_Tecla-ref_teclas.begin();
			teclas_nave.push_back(teclas_sfml[posicion]);
			continue;
		}else{
			if(x.length()==1){
				char p[2];//Es un caracter, pero tiene 2 espacios por el caracter especial del c_string	
				strcpy(p,x.c_str());
				int caract_ascii = static_cast<int>(p[0]);
				if(caract_ascii>=65){
					teclas_nave.push_back(static_cast<Keyboard::Key>(caract_ascii-65));
					continue;
				}else{
					teclas_nave.push_back(static_cast<Keyboard::Key>(caract_ascii-22));
					continue;
				}
			}
		}
	}
	return teclas_nave;
}
vector<string> Settings::obtenerStringTeclas()const
{
	return m_stringsTeclas;
}
void Settings::actualizarControles(vector<string> v)
{
	int k =0;
	for(int i=0;i<m_teclasCrudo.size();i++) 
	{
		if(m_teclasCrudo[i].find_first_of('#',0)){
			m_teclasCrudo[i]=v[k];
			++k;
		}
	}
	ofstream archi("Set_Controls.txt",ios::trunc);
	if(!archi.is_open()) throw runtime_error("No se pudo abrir el archivo, graba controles");
	for(string &s:m_teclasCrudo)
	{
		archi<<s<<endl;
	}
	archi.close();
}
