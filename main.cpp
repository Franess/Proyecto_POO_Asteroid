#include <SFML/Graphics.hpp>
#include "OnePlayer.h"
#include "Settings.h"
#include "PantallaInicio.h"

using namespace std;
using namespace sf;



int main(int argc, char *argv[]){
	Juego j(new PantallaInicio);
	j.jugar();
	return 0;
}
//Final main	

