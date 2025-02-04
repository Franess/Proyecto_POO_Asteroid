#ifndef SETTINGS_H
#define SETTINGS_H
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <string>
using namespace std;
using namespace sf;

class Settings {
public:
	Settings();
	vector<Keyboard::Key>obtenerControles() ;
	vector<string> obtenerStringTeclas()const;
	void actualizarControles(vector<string> v);
private:
	vector<string> m_stringsTeclas, m_teclasCrudo;
};

#endif

