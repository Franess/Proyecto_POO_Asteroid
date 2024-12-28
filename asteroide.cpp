#include "asteroide.h"
#include "rng.h"

using namespace std;
asteroide::asteroide() {
	tex.loadFromFile("asteroide.png");
	spr.setTexture(tex);
	spr.setPosition(RNG(640-20),RNG(360-20));
}
void asteroide::actualizar(){
spr.move(0,0);	
}
void asteroide::dibujar(RenderWindow &win){
	win.draw(spr);
}
