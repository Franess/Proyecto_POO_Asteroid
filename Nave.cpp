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
	m_nave.setPoint(2,Vector2f(10,25));
	m_nave.setPoint(3,Vector2f(0,30));
	//El diseño esta pensado para tener un tamanio de 20x30 pixeles
	m_nave.setOutlineThickness(2);
	m_nave.setOutlineColor({255,255,255,255});
	
	m_nave.setOrigin(10,15);
	m_nave.setPosition(320,180);
	m_nave.setFillColor({239,254,0,128});
	m_teclas = s.obtenerControles();
	Vector2f aux = m_nave.getOrigin() - m_nave.getPoint(0);
	m_radio=sqrt(aux.x*aux.x + aux.y*aux.y);
}

void Nave::actualizar(){
	if(Keyboard::isKeyPressed(m_teclas[1])){//rotar derecha
		m_nave.rotate(3);
		if(time_pressed>0 and !Keyboard::isKeyPressed(m_teclas[3])){
			time_pressed-=1.0/45;
		}
	}
	if(Keyboard::isKeyPressed(m_teclas[2])){//Rotar izquierda
		m_nave.rotate(-3);
		if(time_pressed>0 and !Keyboard::isKeyPressed(m_teclas[3])){ 
			time_pressed-=1.0/45;
		}
	}	
	if(Keyboard::isKeyPressed(m_teclas[3])){	//Avanzar nave
		float m_rapidez=(1.0/4)*(exp(time_pressed)-1);	//la rapidez es una funcion con respecto al tiempo
		radianes_rot = m_nave.getRotation()*M_PI/180;
		m_vecDireccion.x=m_rapidez*cos(radianes_rot-M_PI/2);
		m_vecDireccion.y=m_rapidez*sin(radianes_rot-M_PI/2);
		Vector2f nueva_direccion(m_rapidez*cos(radianes_rot-M_PI/2),m_rapidez*sin(radianes_rot-M_PI/2));
		m_nave.move(m_vecDireccion);
		if(time_pressed<=(6.0/2)){//Tiempo que se mantiene presionada la tecla.
			time_pressed+=1.0/40;
		}
	}
	if(Keyboard::isKeyPressed(m_teclas[4])){//Frenar Nave
		/*cambiarInmunidad();*/
		if(time_pressed>0){//Cuando se suelta la tecla, ese tiempo se "Reduce", que determina el efecto de  
			time_pressed-=1.0/20;
		}
	}
	if(time_pressed>0){//Cuando se suelta la tecla, ese tiempo se "Reduce", que determina el efecto de  
		time_pressed-=1.0/120;
	}
	float m_rapidez=-log(conversionElapsed((1.0/4)*(exp(time_pressed)-1)))+2.3;	//la rapidez es una funcion con respecto al tiempo
	m_vecDireccion.x=m_rapidez*cos(radianes_rot-M_PI/2);
	m_vecDireccion.y=m_rapidez*sin(radianes_rot-M_PI/2);
	m_nave.move(m_vecDireccion);
}
void Nave::dibujar(RenderWindow &win)
{
	win.draw(m_nave);
}

bool Nave::disparar(int cant_proye){
	if(Keyboard::isKeyPressed(m_teclas[0]) && cant_proye<=5 && no_disparo && !m_colision){
		no_disparo= false;
		return true;
	}
	if(!Keyboard::isKeyPressed(m_teclas[0]))
		no_disparo=true;
	return false;
	
	
}

Proyectil Nave::generarDisparo()const{
	float radianes_rot = m_nave.getRotation()*M_PI/180;
	/*La posicion del disparo esta dada por la ecuacion parametrica de la circunferencia donde
	x=a+r*cos(t) // y =b+r*sen(t)
	con (a,b) coordenadas del centro de la circunferencia, r el radio y t el angulo en radianes*/
	Vector2f vec_posicion = m_nave.getPosition();
	Vector2f pos_bala(vec_posicion.x+(m_radio+2)*cos(radianes_rot-M_PI/2),vec_posicion.y+(m_radio+2)*sin(radianes_rot-M_PI/2));
	
	Proyectil proye(pos_bala,m_nave.getRotation());
	return proye;
}
Vector2f Nave::obtenerFoco1()const{
	Vector2f vec_posicion = m_nave.getPosition();
	Vector2f aux(vec_posicion.x+(4.0/15)*m_radio*cos(radianes_rot-M_PI/2),vec_posicion.y+(4.0/15)*m_radio*sin(radianes_rot-M_PI/2));
	return aux;
}
Vector2f Nave::obtenerFoco2()const{
	Vector2f vec_posicion = m_nave.getPosition();
	Vector2f aux(vec_posicion.x+(1.0/3)*m_radio*cos(radianes_rot+M_PI/2),vec_posicion.y+(1.0/3)*m_radio*sin(radianes_rot+M_PI/2));
	return aux;
}//El mayor

float Nave::obtenerRadioFoco1()const{
	return m_radio*(11.f/15);
}
float Nave::obtenerRadioFoco2()const{
	return m_radio*(13.f/15);
}

void Nave::respawn(){
	m_nave.setPosition(320,180);
	time_pressed=0;
}
bool Nave::obtenerInmunidad(){
	return m_Noinmunidad;
}
void Nave::cambiarInmunidad(){
	if(m_Noinmunidad)
		m_Noinmunidad=false;
	else
		m_Noinmunidad=true;
	   
}	
void Nave::marcarTiempo(){
	m_tiempo = m_reloj.restart();
}
Time Nave::obtenerTiempo(){
	return m_reloj.getElapsedTime();
}

Vector2f Nave::obtenerPosicion()const{
	return m_nave.getPosition();
}
float Nave::obtenerRadioNave()const{
	return m_radio;
}
void Nave::cambiarColision(){
	if(m_colision)
		m_colision=false;
	else
		m_colision=true;
	
}	
bool Nave::obtenerColision(){
	return m_colision;
}
void Nave::cambiarTransparencia(){
	if(m_colision){
		m_nave.setOutlineColor({255,255,255,0});
		m_nave.setFillColor({239,254,0,0});
	}else{
		m_nave.setOutlineColor({255,255,255,255});
		m_nave.setFillColor({239,254,0,128});
	}
}
void Nave::establecerPosicion(Vector2f pos_nueva)
{
	m_nave.setPosition(pos_nueva);
}
int Nave::obtenerVidas()const
{
	return m_vidas;
}
void Nave::sumarVidas(int cantidad)
{
	m_vidas+=cantidad;
}
bool Nave::restarVidas()
{
	if(m_vidas >=1 )
	{
		m_vidas-=1;
		return true;
	}else 
	   return false;
}
void Nave::establecerVidas(int cant)
{
	m_vidas=cant;
}
