#include "Settings.h"

bool operator!=(Config c1,Config c2)
{
	if(c1.nom_config!=c2.nom_config &&c1.i_valor!=c2.i_valor && c1.f_valor!=c2.f_valor)
		return true; 
	else
		return false;
}

using namespace std;

Settings::Settings() {
	
	//Abre el archivo y guarda las lineas de texto de interes para el programa
	fstream archi("config\\Set_Controls.txt",ios::in);
	if(!archi.is_open()){throw runtime_error("No se pudo abrir el archivo");}
	string s;
	while(getline(archi,s)){
		m_teclasCrudo.push_back(s);
		if(s.find_first_of('#',0)){
			m_stringsTeclas.push_back(s);
		}
	}
	archi.close();
	archi.open("assets\\dat\\configuracionesJuego.poo",ios::binary|ios::in);
	if(!archi.is_open()){throw runtime_error("No se pudo abrir el archivo");}
	archi.seekg(0);
	Config c;
	while(archi.read(reinterpret_cast<char*>(&c),sizeof(c)))
	{
		m_configuraciones.push_back(c);
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
	ofstream archi("config\\Set_Controls.txt",ios::trunc);
	if(!archi.is_open()) throw runtime_error("No se pudo abrir el archivo, graba controles");
	for(string &s:m_teclasCrudo)
	{
		archi<<s<<endl;
	}
	archi.close();
}
vector<Config> Settings::obtenerConfiguracion()const
{
	return m_configuraciones;
}
void Settings::actualizarConfiguracion(vector<Config> nuevas_configuraciones)
{
	fstream archi("configuracionesJuego.poo",ios::binary|ios::out|ios::trunc);
	if(!archi.is_open())throw runtime_error("No se pudo arbir el archivo");
	archi.seekp(0);
	for(Config &x:nuevas_configuraciones)
	{
		archi.write(reinterpret_cast<const char*>(&x),sizeof(x));
	}
	archi.close();
}
