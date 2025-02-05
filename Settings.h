#ifndef SETTINGS_H
#define SETTINGS_H
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <string>
using namespace std;
using namespace sf;

struct Config
{
	char nom_config[9];
	int i_valor;
	float f_valor;
};

class Settings {
public:
	Settings(); 
	vector<Keyboard::Key>obtenerControles() ;
	vector<string> obtenerStringTeclas()const;
	void actualizarControles(vector<string> v);
private:
	vector<string> m_stringsTeclas, m_teclasCrudo;
	vector<Config> m_configuraciones;
};

#endif

