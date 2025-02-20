#include "EscenaArchivos.h"

EscenaArchivos::EscenaArchivos(int selector_escenaSig)
{
	//La logica con la que se manejan los estados de los archivos es:
	//Suponiendo que siempre estan abiertos. Entonces, si no se pudieron abir, es que NO se abrieron
	m_escalas.resize(2,0);
	m_fuente.loadFromFile("SixtyfourConvergence-Regular-VariableFont_BLED,SCAN,XELA,YELA.ttf");
	m_tituloPantalla.setFont(m_fuente);
	m_tituloPantalla.setString("Regenerar archivos");
	m_tituloPantalla.setCharacterSize(20);
	m_tituloPantalla.setScale(0.5,1);
	auto info_texto = m_tituloPantalla.getLocalBounds();
	m_tituloPantalla.setOrigin(info_texto.width/2,info_texto.height/2);
	m_tituloPantalla.setPosition(320,10);
	
	m_seccionTitulo.setSize(sf::Vector2f(640,30));
	m_seccionTitulo.setOutlineColor({255,255,255});
	m_seccionTitulo.setOutlineThickness(2);
	m_seccionTitulo.setFillColor({0,0,0,0});
	m_seccionTitulo.setOrigin(0,0);
	m_seccionTitulo.setPosition(0,0);
	
	m_indicadorArchivo.setFont(m_fuente);
	m_indicadorArchivo.setString("Archivo");
	m_indicadorArchivo.setCharacterSize(20);
	m_indicadorArchivo.setScale(0.5,1);
	info_texto = m_indicadorArchivo.getLocalBounds();
	m_indicadorArchivo.setOrigin(info_texto.width/2,info_texto.height/2);
	m_indicadorArchivo.setPosition(160,45);
	
	m_indicadorEstado.setFont(m_fuente);
	m_indicadorEstado.setString("Estado");
	m_indicadorEstado.setCharacterSize(20);
	m_indicadorEstado.setScale(0.5,1);
	info_texto = m_indicadorEstado.getLocalBounds();
	m_indicadorEstado.setOrigin(info_texto.width/2,info_texto.height/2);
	m_indicadorEstado.setPosition(480,45);
	
	std::vector<std::string> nombres_botones = {"Puntaje","Configuraciones","Controles"};
	Boton boton_archivos(nombres_botones[0],&m_fuente,25);
	boton_archivos.escalado(0.5,1.f);
	boton_archivos.establecerPosicion(160,90);
	m_vecbotones.push_back(boton_archivos);
	//Genero el resto de los botones
	//El indice comienza en uno ya que el primer boton ya esta generado como referencia
	for(int i=1;i<nombres_botones.size();i++) 
	{
		Boton aux(nombres_botones[i],&m_fuente,25);
		aux.escalado(0.5,1.f);
		sf::Vector2f vec_pos = m_vecbotones[i-1].obtenerPosicion();
		aux.establecerPosicion(160,vec_pos.y + 10 + m_vecbotones[i-1].obtenerAltoBorde());
		m_vecbotones.push_back(aux);
	}
	
	std::vector<std::string> nombres_archivos = {"puntaje.poo","configuracionesJuego.poo","Set_Controls.txt"};
	//El parametro de control del if es la cantidad de archivos binarios que se manejan en el juego
	int cantidad_archivos=2;
	for(int i=0;i<nombres_archivos.size();i++) 
	{
		fstream archi;
		archi.open(nombres_archivos[i],ios::in|ios::binary);
		m_estadosArchivos.push_back(archi.is_open());
		archi.close();
	}
	//Generacion de los textos que indican si esta o no el archivo
	for(int i=0;i<m_estadosArchivos.size();i++) 
	{
		sf::Text txt_aux;
		txt_aux.setFont(m_fuente);
		txt_aux.setCharacterSize(25);
		if(!m_estadosArchivos[i])
		{
			txt_aux.setString("No disponible");
			txt_aux.setFillColor({255,0,0});
		}
		else
		{
			txt_aux.setString("Disponible");
			txt_aux.setFillColor({0,255,0});
		}
		auto info_texto = txt_aux.getLocalBounds();
		txt_aux.setOrigin(info_texto.width/2,info_texto.height/2);
		sf::Vector2f vec_pos = m_vecbotones[i].obtenerPosicion();
		txt_aux.setScale(0.5,1);
		txt_aux.setPosition(480,vec_pos.y);
		m_textosEstados.push_back(txt_aux);
	}
}
void EscenaArchivos::Actualizar(Juego & j) 
{
	std::vector<std::string> nombres_archivos = {"puntaje.poo","configuracionesJuego.poo","Set_Controls.txt"};
	int cantidad_archivos=2;
	for(int i=0;i<nombres_archivos.size();i++) 
	{
		fstream archi;
		archi.open(nombres_archivos[i],ios::binary|ios::in);
		m_estadosArchivos[i]=archi.is_open();
		archi.close();
	}
	contador_estados = 0;
	for(int i = 0;i<m_estadosArchivos.size();++i)
	{
		if(m_estadosArchivos[i]) 
		{
			++contador_estados;
			m_textosEstados[i].setString("Disponible");
			m_textosEstados[i].setFillColor({0,255,0});
		}else
		{
			m_textosEstados[i].setString("No Disponible");
			m_textosEstados[i].setFillColor({255,0,0});
		}
	}
	if(contador_estados==3)
	{
		
		j.CambiarEscena(new PantallaInicio);
	}
}

void EscenaArchivos::Dibujar(sf::RenderWindow & win)
{
	m_escalas = actualizarEscalares(win);
	win.draw(m_tituloPantalla);
	win.draw(m_seccionTitulo);
	win.draw(m_indicadorArchivo);
	win.draw(m_indicadorEstado);
	for(Boton &x:m_vecbotones) x.dibujar(win);
	for(sf::Text &x:m_textosEstados) win.draw(x);
}

void EscenaArchivos::ProcesarEvento(Juego & j, sf::Event e) 
{
	if(e.type == sf::Event::MouseMoved)
	{
		sf::Vector2f pos_mouse(e.mouseMove.x,e.mouseMove.y);
		for(Boton &x:m_vecbotones){
			if(calculo_sobreposicion(pos_mouse,x,m_escalas[0],m_escalas[1]))
			{ 
				x.colorFondo({190,255,250,50});
			}
			else x.colorFondo({0,0,0,0});
		}
	}
	//La cantidad de condicionales depende de la cantidad de botones generados, es decir, de la cantidad de archivos que se utilicen
	sf::Vector2f pos_mouse(e.mouseButton.x,e.mouseButton.y);
	if(e.type == sf::Event::MouseButtonReleased)
	{
		if(calculo_sobreposicion(pos_mouse,m_vecbotones[0],m_escalas[0],m_escalas[1])&&e.mouseButton.button == sf::Mouse::Left )
		{ 
			m_settings.regenerarPuntaje();
		}
		if(calculo_sobreposicion(pos_mouse,m_vecbotones[1],m_escalas[0],m_escalas[1])&&e.mouseButton.button == sf::Mouse::Left )
		{ 
			m_settings.regenerarConfiguracion();
		}
		if(calculo_sobreposicion(pos_mouse,m_vecbotones[2],m_escalas[0],m_escalas[1])&&e.mouseButton.button == sf::Mouse::Left )
		{ 
			m_settings.regenerarControles();
		}
	}
	if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Escape)
	{
		j.terminar();
	}
}
EscenaArchivos::~EscenaArchivos()
{
	
}
