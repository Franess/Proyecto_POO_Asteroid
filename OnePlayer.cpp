#include "OnePlayer.h"
#include "PantallaInicio.h"
#include "Escena_Puntaje.h"
#include <sstream>
#include "rng.h"

using namespace std;
using namespace sf;

void reproducir(sf::SoundBuffer &buffer, vector<sf::Sound*> &s, float volume=90, bool random_pitch=1){
	sf::Sound* sound=new sf::Sound();
	(*sound).setBuffer(buffer);
	(*sound).setVolume(volume);
	(*sound).setPitch((1*!random_pitch)+(0.95 + static_cast<float>(RNG(10))/100)*random_pitch);
	(*sound).play();
	s.push_back(sound);
}

void eliminar_s(vector<sf::Sound*> &s){
	
	for (size_t i=0;i<s.size(); ){
		if((*s[i]).getStatus()==sf::Sound::Stopped){
			delete s[i];
			s.erase(s.begin()+i);
		}else{
			++i;
		}
	}
}

bool fuera_limites(Proyectil &d)
{
	Vector2f pos_actual = d.obtenerPosicion();
	if(pos_actual.x<0 or pos_actual.x>640)
		return true;
	if(pos_actual.y<0 or pos_actual.y>360) 
		return true;
	return false;
}
bool colision_naveaste(Nave &n, asteroide &a)
{
	Vector2f vec_foco1 = n.obtenerFoco1() - a.get_posicion();
	Vector2f vec_foco2 = n.obtenerFoco2() - a.get_posicion();
	float limiteNorma_foco1 = n.obtenerRadioFoco1() + a.get_rad(); 
	float limiteNorma_foco2 = n.obtenerRadioFoco2() + a.get_rad();
	float norma_foco1 = sqrt(vec_foco1.x*vec_foco1.x + vec_foco1.y*vec_foco1.y);
	float norma_foco2 = sqrt(vec_foco2.x*vec_foco1.x + vec_foco2.y*vec_foco2.y);
	if((norma_foco1<=limiteNorma_foco1 || norma_foco2<=limiteNorma_foco2) && n.restarVidas())
		return true;
	else
		return false;
	
}
void efectoNaveDestruccion(Efecto *e, Nave &n,RenderWindow &win)
{
	if((n.obtenerTiempo()).asMilliseconds()<3000 && n.obtenerColision()){
		e->actualizar();
		e->dibujar(win);
	}
	if((n.obtenerTiempo()).asMilliseconds()>=3000 && n.obtenerColision()){
		n.cambiarColision();
		n.cambiarTransparencia();
		n.cambiarInmunidad();
		n.respawn();
	}
}
bool tiempoEfecto(AsteroideExplosion &aexp)
{
	if((aexp.obtenerTiempo()).asMilliseconds()>=500)
		return true;
	else
		return false;
}
Vector2f correccionPosicionNave(const Nave &n)
{
	float margen_nave = n.obtenerRadioNave();
	Vector2f pos_nave = n.obtenerPosicion();
	/*Aplico la correcion en x y luego en y.
	Se deja un margen para que la nave desaparezca de la pantalla
	y luego reaparezca en la posicion que corresponda
	*/
	if(pos_nave.x<=(0-margen_nave))
		pos_nave.x = 639+margen_nave;
	else
	{
		if(pos_nave.x>=(640+margen_nave))
			pos_nave.x = 1-margen_nave;
	}
	if(pos_nave.y<=(0-margen_nave))
		pos_nave.y = 359+margen_nave;
	else
	{
		if(pos_nave.y>=(360+margen_nave))
			pos_nave.y = 1-margen_nave;
	}
	return pos_nave;
}

OnePlayer::OnePlayer(Settings &s):m_navesita(s)
{
	bool estado_fuente = m_fuente.loadFromFile("SixtyfourConvergence-Regular-VariableFont_BLED,SCAN,XELA,YELA.ttf");
	m_configuraciones = s.obtenerConfiguracion();
	m_msjTeclaMenu.setFont(m_fuente);
	m_msjTeclaMenu.setCharacterSize(10);
	m_msjTeclaMenu.setString("<Presione 'esc' para volver al menu, se perderan los puntos>");
	m_msjTeclaMenu.setOrigin(0,0);
	m_msjTeclaMenu.setScale(0.5,1);
	m_msjTeclaMenu.setPosition(180,345);
	mtex_asteroide = new Texture;
	(*mtex_asteroide).loadFromFile("asteroide.png");
	stringstream ss;
	ss<<"Vidas: "<<m_navesita.obtenerVidas();
	Boton boton_vidas(ss.str(),&m_fuente,10);
	boton_vidas.establecerPosicion(50,320);
	vec_botones.push_back(boton_vidas);//Corresponde a la pos [0]
	ss.str("");
	ss<<"Puntos: "<<m_tabla.get_puntos();
	Boton boton_ptos(ss.str(),&m_fuente,10);
	boton_ptos.establecerPosicion(320,20);
	vec_botones.push_back(boton_ptos);//Corresponde a la pos [1]
	m_navesita.establecerVidas(m_configuraciones[0].i_valor);
	
	m_musica.openFromFile("Mega Man X4 - Military Train.wav");
	m_musica.setLoop(true);
	m_musica.setVolume(40);
	m_musica.play();
	
	sf::SoundBuffer aux_buffer;
	aux_buffer.loadFromFile("01 - MMX - X Regular Shot.wav");
	m_buffer.push_back(aux_buffer);
	aux_buffer.loadFromFile("125 - MMX - Wing Flap (5).wav");
	m_buffer.push_back(aux_buffer);
	
	aux_buffer.loadFromFile("11 - MMX - X Die.wav");
	m_buffer.push_back(aux_buffer);

	aux_buffer.loadFromFile("115 - MMX - Underwater Bubble.wav");
	m_buffer.push_back(aux_buffer);
}

void OnePlayer::Actualizar (Juego &j) 
{
	m_prueba++;
	if (m_prueba%120==0){
		respawn(m_ast);
		if(  (m_ast.size()<3) or (m_tabla.get_puntos()>m_puntos_para_siguiente)  ){
			spawn(m_ast,mtex_asteroide);
			m_puntos_para_siguiente=m_puntos_para_siguiente*1.6;
		}
		m_tabla.actualizar_puntos_j(m_ast.size()*10);
	}
	if(destruir(m_ast,mproye_pantalla,mefec_explosion,m_tabla)){
		reproducir(m_buffer[1],m_sound);
	}

	colision(m_ast);
	for(int i=0;i<m_ast.size();i++) {  
		m_ast[i].actualizar();
	}
	
	if(m_navesita.disparar(mproye_pantalla.size())){
		mproye_pantalla.push_back(m_navesita.generarDisparo());
		reproducir(m_buffer[0],m_sound,75,0);
		/*m_s_disparo++;
		m_sound[m_s_disparo].play();
		if(m_s_disparo==6){m_s_disparo=0;}*/
	}
	for(Proyectil &x:mproye_pantalla) x.actualizar();
	for(AsteroideExplosion &x:mefec_explosion) x.actualizar();
	
	//remueve el proyectil que se encuentra fuera de los limites de la pantalla de juego
	auto it_elimproye = remove_if(mproye_pantalla.begin(),mproye_pantalla.end(),fuera_limites);	//elimproye => eliminar proyectil
	mproye_pantalla.erase(it_elimproye,mproye_pantalla.end());
	
	//Elimina los efectos de explosion pasados un limite de tiempo
	auto it_elimexp = remove_if(mefec_explosion.begin(),mefec_explosion.end(),tiempoEfecto);
	mefec_explosion.erase(it_elimexp,mefec_explosion.end());
	
	Nave nav = this->m_navesita;
	auto it_colisionAsteNave = find_if(m_ast.begin(),m_ast.end(),[&nav](asteroide &a){return colision_naveaste(nav,a);});
	if(it_colisionAsteNave!=m_ast.end() && m_navesita.obtenerInmunidad() && m_navesita.restarVidas()){
		(*it_colisionAsteNave).r_size();
		(*it_colisionAsteNave).cambiar_objetivo();
		(*it_colisionAsteNave).reposicionar();
		(*it_colisionAsteNave).set_direccion();
		if(m_vfx){
			delete m_vfx;
		}
		m_vfx = new OndaConcentrica(m_navesita.obtenerPosicion(),m_navesita.obtenerRadioNave());
		m_navesita.marcarTiempo();
		m_navesita.cambiarColision();
		m_navesita.cambiarTransparencia();
		m_navesita.cambiarInmunidad();
		
		reproducir(m_buffer[2],m_sound,25,0);
	}
	if(m_navesita.obtenerVidas()==0)
	{
		//j.CambiarEscena(new Escena_Puntaje);
		m_musica.stop();
		j.CambiarEscena(new JuegoTerminado(m_tabla.get_puntos()));
	}
	if(m_navesita.obtenerVidas()==1) vec_botones[0].establecerColorTexto({255,0,0});
	stringstream ss;
	ss<<"Vidas: "<<m_navesita.obtenerVidas();
	vec_botones[0].establecerTexto(ss.str());
	ss.str("");
	ss<<"Puntos: "<<m_tabla.get_puntos();
	vec_botones[1].establecerTexto(ss.str());
	
	if((m_navesita.obtenerTiempo()).asMilliseconds()<3000 && m_navesita.obtenerColision())m_vfx->actualizar();
	
	if((m_navesita.obtenerTiempo()).asMilliseconds()>=3000 && m_navesita.obtenerColision()){
		m_navesita.cambiarColision();
		m_navesita.cambiarTransparencia();
		m_navesita.respawn();
		reproducir(m_buffer[3],m_sound,80,0);
	}
	if((m_navesita.obtenerTiempo()).asMilliseconds()>=4500)
	{
		m_navesita.cambiarInmunidad();
	}
	for(Boton &x:vec_botones) x.actualizar();
	Vector2f vecPos_correccion = correccionPosicionNave(m_navesita);
	m_navesita.establecerPosicion(vecPos_correccion);
	m_navesita.actualizar();
	
	eliminar_s(m_sound);
}

void OnePlayer::Dibujar (sf::RenderWindow & win) 
{
	for(int i=0;i<m_ast.size();i++) m_ast[i].dibujar(win);
	for(Proyectil &x:mproye_pantalla) x.dibujar(win);
	for(AsteroideExplosion &x:mefec_explosion) x.dibujar(win);
	for(Boton &x:vec_botones) x.dibujar(win);
	if((m_navesita.obtenerTiempo()).asMilliseconds()<3000 && m_navesita.obtenerColision()) m_vfx->dibujar(win);
	win.draw(m_msjTeclaMenu);
	m_navesita.dibujar(win);
}
OnePlayer::~OnePlayer()
{
	
	if(m_vfx){
		delete m_vfx;
	}
	delete mtex_asteroide;
	
	for(sf::Sound* aux:m_sound){
		(*aux).stop();
		delete aux;
	}
	m_sound.clear();
	m_buffer.clear();
	m_musica.stop();
}
void OnePlayer::ProcesarEvento(Juego &j, sf::Event e)
{
	if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Escape)
	{
		j.CambiarEscena(new PantallaInicio);
	}
}
