#include "Nave.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include "Settings.h"
using namespace std;
using namespace sf;
//Funcion Auxiliar
float conversionElapsed(float x){
	return exp(log(10)-x);
}

Nave::Nave(Settings &s)
{
	m_nave.setPointCount(4);
	//Definen la posicion de los vertices de la nava
	m_nave.setPoint(0,Vector2f(10,0));
	m_nave.setPoint(1,Vector2f(20,30));
	m_nave.setPoint(2,Vector2f(10,20));
	m_nave.setPoint(3,Vector2f(0,30));
	//El diseño esta pensado para tener un tamanio de 20x30 pixeles
	m_nave.setOutlineThickness(2);
	m_nave.setOutlineColor({255,255,255,255});
	
	m_nave.setOrigin(10,15);
	m_nave.setPosition(100,100);
	m_nave.setFillColor({239,254,0,128});
	m_teclas = s.obtenerControles();
}

void Nave::actualizar(){
	if(Keyboard::isKeyPressed(m_teclas[1]))//rotar derecha
		m_nave.rotate(3);
	if(Keyboard::isKeyPressed(m_teclas[2]))//Rotar izquierda
		m_nave.rotate(-3);	
	if(Keyboard::isKeyPressed(m_teclas[3])){	//Avanzar nave
		float m_rapidez=(1.0/4)*(exp(elapsed_time)-1);	//la rapidez es una funcion con respecto al tiempo
		radianes_rot = m_nave.getRotation()*M_PI/180;
		m_vecDireccion.x=m_rapidez*cos(radianes_rot-M_PI/2);
		m_vecDireccion.y=m_rapidez*sin(radianes_rot-M_PI/2);
		Vector2f nueva_direccion(m_rapidez*cos(radianes_rot-M_PI/2),m_rapidez*sin(radianes_rot-M_PI/2));
		m_nave.move(m_vecDireccion);
		if(elapsed_time<=(6.0/2)){//Tiempo que se mantiene presionada la tecla.
			elapsed_time+=1.0/40;
		}
	}else{
		if(elapsed_time>0){//Cuando se suelta la tecla, ese tiempo se "Reduce", que determina el efecto de  
			elapsed_time-=1.0/120;
		}
		float m_rapidez=-log(conversionElapsed(elapsed_time))+2.3;	//la rapidez es una funcion con respecto al tiempo
		m_vecDireccion.x=m_rapidez*cos(radianes_rot-M_PI/2);
		m_vecDireccion.y=m_rapidez*sin(radianes_rot-M_PI/2);
		m_nave.move(m_vecDireccion);		
	}
	if(Keyboard::isKeyPressed(m_teclas[4])){
		if(elapsed_time>0){//Cuando se suelta la tecla, ese tiempo se "Reduce", que determina el efecto de  
			elapsed_time-=1.0/30;
		}
	}
}
void Nave::dibujar(RenderWindow &win)
{
	win.draw(m_nave);
}

bool Nave::disparar(){
	if(Keyboard::isKeyPressed(m_teclas[0])){
		return true;
	}else{
		return false;
	}
}

Proyectil Nave::generarDisparo()const{
	float radianes_rot = m_nave.getRotation()*M_PI/180;
	/*La posicion del disparo esta dada por la ecuacion parametrica de la circunferencia donde
	x=a+r*cos(t) // y =b+r*sen(t)
	con (a,b) coordenadas del centro de la circunferencia, r el radio y t el angulo en radianes*/
	Vector2f vec_posicion = m_nave.getPosition(); 
	Vector2f pos_bala(vec_posicion.x+20*cos(radianes_rot-M_PI/2),vec_posicion.y+20*sin(radianes_rot-M_PI/2));
	
	Proyectil proye(pos_bala,m_nave.getRotation());
	return proye;
}
