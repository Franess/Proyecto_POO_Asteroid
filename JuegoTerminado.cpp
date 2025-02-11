#include "JuegoTerminado.h"
#include <sstream>
#include "rng.h"
#include "funcionesBotones.h"


JuegoTerminado::JuegoTerminado(int puntos_fin):m_puntosFinales(puntos_fin)
{
	bool estado_fuente = m_fuente.loadFromFile("assets\\dat\\SixtyfourConvergence-Regular-VariableFont_BLED,SCAN,XELA,YELA.ttf");
	if(!estado_fuente) throw runtime_error("No se encuentra la fuente Roboto_Condensed-Bold.ttf");
	bool estado_imgFondo = m_texturaFondo.loadFromFile("assets\\texture\\fondoPantallaInicio.jpg");
	if(!estado_imgFondo) throw runtime_error("No se encuentra el fondo fondoJuegoTerminado.jpg");
	bool estado_navepixel = m_texturaNavePixel.loadFromFile("assets\\texture\\navepixelada.png");
	if(!estado_navepixel) throw runtime_error("No se encuentra la textura navepixelada.png");
	m_fondo.setTexture(m_texturaFondo);
	m_fondo.setOrigin(0,0);
	m_fondo.setPosition(0,0);
	m_fondo.setScale(1.0/2,1.0/2);
	m_escalares.resize(2,0);
	m_navePixel.setTexture(m_texturaNavePixel);
	m_navePixel.setOrigin(0,0);
	m_navePixel.setPosition(443,28);
	m_navePixel.setScale(1.5,1.5);
	m_navePixel.setRotation(15);
	
	m_tituloPantalla.setFont(m_fuente);
	m_tituloPantalla.setCharacterSize(50);
	m_tituloPantalla.setString("JUEGO TERMIN  DO");
	m_tituloPantalla.setScale(0.5,1);
	auto m_aux_size=m_tituloPantalla.getLocalBounds();
	m_tituloPantalla.setOrigin(m_aux_size.width/2,m_aux_size.height/2);
	
	sf::Rect<float> aux_medidas = m_tituloPantalla.getGlobalBounds();
	/*m_tituloPantalla.setOrigin(aux_medidas.width/2,aux_medidas.height/2);
	*/
	m_tituloPantalla.setPosition(320,50);
	
	m_msjTeclaMenu.setFont(m_fuente);
	m_msjTeclaMenu.setCharacterSize(10);
	m_msjTeclaMenu.setString("<Presione 'esc' para volver al menu sin guardar el puntaje>");
	m_aux_size=m_msjTeclaMenu.getLocalBounds();
	m_msjTeclaMenu.setOrigin(m_aux_size.width/2,m_aux_size.height/2);
	m_msjTeclaMenu.setPosition(320,345);
	m_msjTeclaMenu.setScale(0.5,1);
	
	std::stringstream ss;
	ss<<"Puntaje Final: "<<puntos_fin;
	m_mostrarPuntos = Boton(ss.str(),&m_fuente,30);
	m_mostrarPuntos.establecerPosicion(320,120);
	m_btnGuardar = Boton("Guardar",&m_fuente,30);
	m_btnGuardar.establecerPosicion(320,300);
	m_btnGuardar.escalado(0.5,1);
	
	m_textoAclaracion.setFont(m_fuente);
	m_textoAclaracion.setCharacterSize(15);
	m_textoAclaracion.setString("<Ingrese su nombre (max caracteres = 15)>");
	m_aux_size=m_textoAclaracion.getLocalBounds();
	m_textoAclaracion.setOrigin(m_aux_size.width/2,m_aux_size.height/2);
	m_textoAclaracion.setScale(0.5,1);
	m_textoAclaracion.setPosition(320,165);
	
	
	
	m_textoEntrada = InputText(m_fuente,25,{255,255,255});
	m_textoEntrada.setMaxChars(15);
	m_textoEntrada.setSingleWord(true);
	
	m_aux_size=m_textoEntrada.getLocalBounds();
	m_textoEntrada.setOrigin(m_aux_size.width/2,m_aux_size.height/2);
	m_textoEntrada.setScale(0.5,1);
	m_textoEntrada.setPosition(225,190);
	
	m_msjFaltaNombre.setFont(m_fuente);
	m_msjFaltaNombre.setCharacterSize(18);
	m_msjFaltaNombre.setString("<Ingrese un nombre por favor>");
	
	m_aux_size=m_msjFaltaNombre.getLocalBounds();
	m_msjFaltaNombre.setOrigin(m_aux_size.width/2,m_aux_size.height/2);
	m_msjFaltaNombre.setScale(0.5,1);
	
	m_msjFaltaNombre.setPosition(320,230);
	m_msjFaltaNombre.setFillColor({0,0,0,0});
	
	m_musica.openFromFile("assets\\sound\\Shop - The Legend of Zelda_ Ocarina of Time OST  Remastered.wav");
	m_musica.setLoop(true);
	m_musica.setVolume(32);
	m_musica.play();
}

void JuegoTerminado::Actualizar (Juego & j) 
{
	m_textoEntrada.update();
	m_mostrarPuntos.actualizar();
	//Cambio el tipo de entero a el entero sf::Uint8 para evitar el warning.
	m_mostrarPuntos.establecerColorBordes({static_cast<sf::Uint8>(RNG(255)),static_cast<sf::Uint8>(RNG(255)),static_cast<sf::Uint8>(RNG(255))});
	m_mostrarPuntos.establecerColorTexto({static_cast<sf::Uint8>(RNG(255)),static_cast<sf::Uint8>(RNG(255)),static_cast<sf::Uint8>(RNG(255))});
}

void JuegoTerminado::Dibujar (sf::RenderWindow & win) 
{
	win.clear({0,0,0});
	m_escalares = actualizarEscalares(win);
	win.draw(m_fondo);
	win.draw(m_tituloPantalla);
	win.draw(m_navePixel);
	win.draw(m_msjTeclaMenu);
	m_mostrarPuntos.dibujar(win);
	m_btnGuardar.dibujar(win);
	win.draw(m_textoAclaracion);
	win.draw(m_textoEntrada);
	win.draw(m_msjFaltaNombre);
}

void JuegoTerminado::ProcesarEvento (Juego &j, sf::Event e) 
{
	m_textoEntrada.processEvent(e);
	if(e.type == sf::Event::MouseMoved)
	{
		sf::Vector2f pos_mouse(e.mouseMove.x,e.mouseMove.y);
		if(calculo_sobreposicion(pos_mouse,m_btnGuardar,m_escalares[0],m_escalares[1]))
		{ 
			m_btnGuardar.colorFondo({190,255,250,50});
		}
		else m_btnGuardar.colorFondo({0,0,0,0});
	}
	if(e.type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2f pos_mouse(e.mouseButton.x,e.mouseButton.y);
		if(calculo_sobreposicion(pos_mouse,m_btnGuardar,m_escalares[0],m_escalares[1]) && e.mouseButton.button == sf::Mouse::Left && m_textoEntrada.getValue()!="")
		{
			//Acá antes de cambiar de pantalla deberia ir la carga de datos (Leo)
			m_tabla.recibir_nombre_j(m_textoEntrada.getString());
			m_tabla.actualizar_puntos_j(m_puntosFinales);
			m_tabla.actualizar_archivo_puntaje();
			j.CambiarEscena(new PantallaInicio);
		}else
		{
			m_msjFaltaNombre.setFillColor({255,0,0});
		}
	}
	if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Escape)
	{
		j.CambiarEscena(new PantallaInicio);
	}
}

