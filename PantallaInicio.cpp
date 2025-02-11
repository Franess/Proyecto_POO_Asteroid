#include "PantallaInicio.h"
using namespace std;

PantallaInicio::PantallaInicio() 
{
	//bool estado_fuente = m_fuente.loadFromFile("Roboto_Condensed-Bold.ttf");
	bool estado_fuente = m_fuente.loadFromFile("SixtyfourConvergence-Regular-VariableFont_BLED,SCAN,XELA,YELA.ttf");
	bool estado_textura = m_textura.loadFromFile("asteroide.png");
	bool estado_imgFondo = m_imgFondo.loadFromFile("fondoPantallaInicio.jpg");
	if(!estado_imgFondo) throw runtime_error("No se encuentra el fondo fondoPantallaInicio.jpg");
	if(!estado_fuente) throw runtime_error("No se encuentra la fuente Roboto_Condensed-Bold.ttf");
	if(!estado_textura) throw runtime_error("No se encuentra la textura asteroide.png");
	m_imagenAsteroide.setTexture(m_textura);
	m_comienzoNombre.setFont(m_fuente);
	m_finalNombre.setFont(m_fuente);
	m_mensajeSalir.setFont(m_fuente);
	m_escalas.resize(2,0);
	m_mensajeSalir.setCharacterSize(10);
	m_comienzoNombre.setCharacterSize(50);
	m_finalNombre.setCharacterSize(50);
	m_finalNombre.setScale(0.5,1);
	m_mensajeSalir.setFillColor({255,255,255});
	m_comienzoNombre.setFillColor({255,255,255});
	m_finalNombre.setFillColor({255,255,255});
	m_mensajeSalir.setString("<Presione la tecla 'esc' para salir>");
	m_comienzoNombre.setString("Aster");
	m_finalNombre.setString("ids");
	boton_presionado=1;
//	m_mensajeSalir.setOrigin(0,0);
//	m_comienzoNombre.setOrigin(0,0);
//	m_finalNombre.setOrigin(0,0);
	
	m_mensajeSalir.setScale(0.5,1);
	m_comienzoNombre.setScale(0.5,1);
	m_finalNombre.setScale(0.5,1);
	
	auto m_text_size=m_mensajeSalir.getLocalBounds();
	m_mensajeSalir.setOrigin(m_text_size.width/2,m_text_size.height/2);
	
	m_text_size=m_comienzoNombre.getLocalBounds();
	m_comienzoNombre.setOrigin(m_text_size.width/2,m_text_size.height/2);
	
	m_text_size=m_finalNombre.getLocalBounds();
	m_finalNombre.setOrigin(m_text_size.width/2,m_text_size.height/2);

//	m_mensajeSalir.setPosition(320,275);
//	m_comienzoNombre.setPosition(205,60);
//	m_finalNombre.setPosition(365,60);
	
	m_mensajeSalir.setPosition(320,275);
	m_comienzoNombre.setPosition(255,80+3);
	m_finalNombre.setPosition(392,77+3);
	
	
	
	
	m_imagenAsteroide.setScale(2.f,2.f);
	m_imagenAsteroide.setOrigin(0,0);
	m_imagenAsteroide.setPosition(340,95);
	sf::Rect<float> aux_Bordesimg = m_imagenAsteroide.getLocalBounds();
	m_imagenAsteroide.setOrigin((aux_Bordesimg.height)/2,(aux_Bordesimg.height)/2);
	
	m_sprFondo.setTexture(m_imgFondo);
	m_sprFondo.setOrigin(0,0);
	m_sprFondo.setPosition(0,0);
	m_sprFondo.setScale(1.0/3,1.0/3);
	
	Boton boton_jugar("Jugar",&m_fuente,30);
	boton_jugar.escalado(0.45,0.9);
	boton_jugar.establecerPosicion(320,150+25);
	vec_botones.push_back(boton_jugar);//vec_botones[0]
	
	Boton boton_puntajes("Puntaje",&m_fuente,30);
	boton_puntajes.escalado(0.45,0.9);
	boton_puntajes.establecerPosicion(320,210+15);
	vec_botones.push_back(boton_puntajes);//vec_botones[1]
	
	Boton boton_ajustes("Ajustes",&m_fuente,15);
	boton_ajustes.escalado(0.5,1);
	boton_ajustes.establecerPosicion(600.f,20.f);
	vec_botones.push_back(boton_ajustes);//vec_botones[2]
	
	m_musica.openFromFile("Megaman X5 - Duff McWhalen Stage.wav");
	m_musica.setLoop(true);
	m_musica.setVolume(20);
	m_musica.play();
}

void PantallaInicio::Actualizar (Juego & j)
{
	m_imagenAsteroide.rotate(3);
	//No se actualizan botones ya que su contenido no cambia.
	//Se actualiza el color solamente solo si esta el puntero del mouse por encima.
}
void PantallaInicio::Dibujar (sf::RenderWindow & win) {
	win.clear({0,0,0});
	m_escalas = actualizarEscalares(win);
	win.draw(m_sprFondo);
	win.draw(m_comienzoNombre);
	win.draw(m_finalNombre);
	win.draw(m_imagenAsteroide);
	win.draw(m_mensajeSalir);
	for(Boton &x:vec_botones){
		x.dibujar(win);
	}
}
void PantallaInicio::ProcesarEvento(Juego &j, sf::Event e)
{
	if(e.type == sf::Event::MouseMoved)
	{
		sf::Vector2f pos_mouse(e.mouseMove.x,e.mouseMove.y);
		for(Boton &x:vec_botones){
			if(calculo_sobreposicion(pos_mouse,x,m_escalas[0],m_escalas[1]))
			{ 
				x.colorFondo({190,255,250,50});
			}
			else x.colorFondo({0,0,0,0});
		}
	}
	if((e.type == sf::Event::MouseButtonReleased) && (boton_presionado))
	{
		boton_presionado=0;
		sf::Vector2f pos_mouse(e.mouseButton.x,e.mouseButton.y);
		if(calculo_sobreposicion(pos_mouse,vec_botones[0],m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
		{
			Settings s;
			j.CambiarEscena(new OnePlayer(s));
		}
		if(calculo_sobreposicion(pos_mouse,vec_botones[1],m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
		{
			j.CambiarEscena(new Escena_Puntaje);
		}
		if(calculo_sobreposicion(pos_mouse,vec_botones[2],m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
		{
			j.CambiarEscena(new menu_ajustes);
		}
	}
	if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Escape)
	{
		j.terminar();
	}
}
PantallaInicio::~PantallaInicio()
{
	
}
