#ifndef SETTINGS_H
#define SETTINGS_H
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "tabla_de_puntos.h"
using namespace std;
using namespace sf;

struct Config
{
	char nom_config[9];
	float f_valor;
	int i_valor;
};


class Settings {
public:
	Settings(); 
	vector<Keyboard::Key>obtenerControles() ;
	vector<string> obtenerStringTeclas()const;
	void actualizarControles(vector<string> v);
	vector<Config> obtenerConfiguracion()const;
	void actualizarConfiguracion(vector<Config> nuevas_configuraciones);
	void regenerarControles();
	void regenerarConfiguracion();
	void regenerarPuntaje();
private:
	vector<string> m_stringsTeclas, m_teclasCrudo;
	vector<Config> m_configuraciones;
};

#endif

