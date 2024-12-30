#ifndef SETTINGS_H
#define SETTINGS_H
#include <vector>
#include <SFML/Window/Keyboard.hpp>
using namespace std;
using namespace sf;

class Settings {
public:
	Settings();
	vector<Keyboard::Key>  obtenerTeclas() const;
private:
	vector<Keyboard::Key> teclas_nave;
};

#endif

