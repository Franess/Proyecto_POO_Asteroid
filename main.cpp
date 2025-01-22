#include <SFML/Graphics.hpp>
#include "OnePlayer.h"
#include "Settings.h"

using namespace std;
using namespace sf;



int main(int argc, char *argv[]){
	Settings sett;
	Juego j(new OnePlayer(sett));
	j.jugar();
	return 0;
}
//Final main	

