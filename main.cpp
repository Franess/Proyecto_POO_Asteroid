#include <SFML/Graphics.hpp>
#include "OnePlayer.h"
#include "Settings.h"
#include "PantallaInicio.h"
#include "Escena_Puntaje.h"
#include "JuegoTerminado.h"
#include "EscenaArchivos.h"

using namespace std;
using namespace sf;


int main(int argc, char *argv[]){
	Juego j(new EscenaArchivos(0));
	j.jugar();
	return 0;
}
//Final main	

