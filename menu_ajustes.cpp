#include "menu_ajustes.h"
#include "funcionesBotones.h"

sf::Text creaTextosControles(std::vector<std::string> vec_mensajes, sf::Text txt_anterior, int indice, sf::Font *fuente)
{
	sf::Text texto(vec_mensajes[indice],*fuente,15);
	texto.setScale(0.5,1);
	texto.setOrigin(0,0);
	sf::Rect<float> info_texto = texto.getLocalBounds();
	sf::Vector2f pos_anterior = txt_anterior.getPosition();
	texto.setPosition(107,pos_anterior.y+info_texto.height+20);
	return texto;
}

Boton generarBotonSelecc(sf::Text &t,sf::Font *fuente)
{
	Boton btn("...",fuente,15);
	btn.escalado(0.5,1);
	sf::Rect<float> info_texto = t.getLocalBounds();
	sf::Vector2f pos_txt = t.getPosition();
	btn.establecerPosicion(620, pos_txt.y+info_texto.height/2);
	return btn;
}

void actualizarTextoControles(std::vector<std::string> &sControles,std::vector<std::string> cActuales,std::vector<sf::Text> &tc)
{
	std::string nuevos_textos;
	for(int i=0;i<sControles.size();i++) 
	{  
		nuevos_textos=sControles[i]+cActuales[i];
		tc[i].setString(nuevos_textos);
	}	
}

menu_ajustes::menu_ajustes() {
	m_fuente.loadFromFile("assets\\dat\\SixtyfourConvergence-Regular-VariableFont_BLED,SCAN,XELA,YELA.ttf");
	m_controlesActuales = m_settings.obtenerStringTeclas();
	m_configuraciones = m_settings.obtenerConfiguracion();
	//Inicializo las divisiones
	m_divisor.setSize(sf::Vector2f(100,360));
	m_divisor.setOutlineColor({255,255,255});
	m_divisor.setFillColor({0,0,0,0});
	m_divisor.setOutlineThickness(2);
	m_divisor.setOrigin(0,0);
	m_divisor.setPosition(0,0);
	
	m_recuadroTitulo.setSize(sf::Vector2f(540,40));
	m_recuadroTitulo.setOutlineColor({255,255,255});
	m_recuadroTitulo.setFillColor({0,0,0,0});
	m_recuadroTitulo.setOutlineThickness(2);
	m_recuadroTitulo.setOrigin(0,0);
	m_recuadroTitulo.setPosition(102,0);
	//Inicializo los botones
	Boton boton_controles("Controles",&m_fuente,20);
	boton_controles.escalado(0.5,1.f);
	boton_controles.establecerPosicion(50,20);
	vec_botones.push_back(boton_controles);//vec_botones[0]
	
	Boton boton_ajuego("Juego",&m_fuente,20);
	boton_ajuego.escalado(0.5,1.f);
	boton_ajuego.establecerPosicion(30,60);
	vec_botones.push_back(boton_ajuego);//vec_botones[1]
	
	Boton boton_guardar("Guardar",&m_fuente,20);
	boton_guardar.escalado(0.5,1.f);
	boton_guardar.establecerPosicion(40,325);
	vec_botones.push_back(boton_guardar);//vec_botones[2]
	
	//Inicializacion Titulo del Ajuste
	m_titulo.setFont(m_fuente);
	m_titulo.setString("Controles");
	m_titulo.setCharacterSize(20);
	m_titulo.setPosition(370,20);
	//Mensaje de la tecla de salir
	m_avisoTeclaSalir.setFont(m_fuente);
	m_avisoTeclaSalir.setString("<Presione 'esc' para salir>");
	m_avisoTeclaSalir.setCharacterSize(10);
	m_avisoTeclaSalir.setScale(0.5,1);
	m_avisoTeclaSalir.setPosition(370,350);
	//Mensaje Guardado para los Controles
	m_avisoGuardadoCtrl.setFont(m_fuente);
	m_avisoGuardadoCtrl.setString("<Sin Guardar>");
	m_avisoGuardadoCtrl.setCharacterSize(10);
	m_avisoGuardadoCtrl.setScale(0.5,1);
	m_avisoGuardadoCtrl.setFillColor({255,0,0});
	m_avisoGuardadoCtrl.setPosition(600,350);
	//Mensaje Guardado para los Juego
	m_avisoGuardadoJuego.setFont(m_fuente);
	m_avisoGuardadoJuego.setString("<Sin Guardar>");
	m_avisoGuardadoJuego.setCharacterSize(10);
	m_avisoGuardadoJuego.setScale(0.5,1);
	m_avisoGuardadoJuego.setFillColor({255,0,0});
	m_avisoGuardadoJuego.setPosition(600,350);
	
	
	//Textos de los ajustes para los controles
	stringControles = {"Disparar=","Rotar Derecha=", "Rotar Izquierda=", "Avanzar=","Frenar="};
	
	sf::Text texto(stringControles[0],m_fuente,15);
	texto.setScale(0.5,1);
	texto.setOrigin(0,0);
	texto.setPosition(107,45);
	textos_controles.push_back(texto);
	
	for(int i=1;i<stringControles.size();i++)
		textos_controles.push_back(creaTextosControles(stringControles,textos_controles[i-1],i,&m_fuente));
	
	actualizarTextoControles(stringControles,m_controlesActuales,textos_controles);
	//Inicializacion InputText para los controles:
	m_textoEntrada = InputText(m_fuente,25,{255,255,255});
	m_textoEntrada.setMaxChars(17);
	m_textoEntrada.setSingleWord(true);
	m_textoEntrada.setOrigin(0,0);
	m_textoEntrada.setScale(0.5,1);
	m_textoEntrada.setPosition(260,310);
	
	for(int i=0;i<textos_controles.size();i++) 
	{
		selec_cambiosCtrl.push_back(generarBotonSelecc(textos_controles[i],&m_fuente));
	}
	
	//Texto indicador de la cantidad de vidas
	m_textoVidas.setFont(m_fuente);
	m_textoVidas.setScale(0.5,1);
	m_textoVidas.setCharacterSize(25);
	m_textoVidas.setOrigin(0,0);
	m_textoVidas.setPosition(107,50);
	std::stringstream ss;
	ss<<"Vidas: "<<m_configuraciones[0].i_valor;
	m_textoVidas.setString(ss.str());
	
	
	//Botones de suma y resta para las vidas
	m_btnsumar = Boton("v++",&m_fuente,25);
	m_btnsumar.escalado(0.5,1.f);
	m_btnsumar.establecerPosicion(250,60);
	
	m_btnrestar= Boton("v--",&m_fuente,25);
	m_btnrestar.escalado(0.5,1.f);
	m_btnrestar.establecerPosicion(300,60);
}

void menu_ajustes::Actualizar (Juego & j) 
{
	m_escalas.resize(2,0);
	sf::Rect<float> info_texto = m_titulo.getLocalBounds();
	m_titulo.setOrigin(info_texto.width/2,info_texto.height/2);
	info_texto = m_avisoTeclaSalir.getLocalBounds();
	m_avisoTeclaSalir.setOrigin(info_texto.width/2,info_texto.height/2);
	info_texto = m_avisoGuardadoCtrl.getLocalBounds();
	m_avisoGuardadoCtrl.setOrigin(info_texto.width/2,info_texto.height/2);
	info_texto = m_avisoGuardadoJuego.getLocalBounds();
	m_avisoGuardadoJuego.setOrigin(info_texto.width/2,info_texto.height/2);
	std::stringstream ss;
	ss<<"Vidas: "<<m_configuraciones[0].i_valor;
	m_textoVidas.setString(ss.str());
	m_textoEntrada.update();
	
}

void menu_ajustes::Dibujar (sf::RenderWindow & win) {
	m_escalas = actualizarEscalares(win);
	win.draw(m_divisor);
	win.draw(m_recuadroTitulo);
	win.draw(m_titulo);
	win.draw(m_avisoTeclaSalir);
	for(Boton &x:vec_botones)x.dibujar(win);
	switch (m_selectorContenidos)
	{
	case 1:
		win.draw(m_textoEntrada);
		win.draw(m_avisoGuardadoCtrl);
		for(Boton &x:selec_cambiosCtrl)x.dibujar(win);
		for(sf::Text &x:textos_controles) win.draw(x);
		break;
	case 2:
		win.draw(m_avisoGuardadoJuego);
		m_btnrestar.dibujar(win);
		m_btnsumar.dibujar(win);
		win.draw(m_textoVidas);
		break;
	}
		
}

void menu_ajustes::ProcesarEvento (Juego & j, sf::Event e) {
	m_textoEntrada.processEvent(e);
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
		for(Boton &x:selec_cambiosCtrl){
			if(calculo_sobreposicion(pos_mouse,x,m_escalas[0],m_escalas[1]))
			{ 
				x.colorFondo({190,255,250,50});
			}
			else x.colorFondo({0,0,0,0});
		}
		if(calculo_sobreposicion(pos_mouse,m_btnsumar,m_escalas[0],m_escalas[1]))
		{ 
			m_btnsumar.colorFondo({190,255,250,50});
		}
		else m_btnsumar.colorFondo({0,0,0,0});
		if(calculo_sobreposicion(pos_mouse,m_btnrestar,m_escalas[0],m_escalas[1]))
		{ 
			m_btnrestar.colorFondo({190,255,250,50});
		}
		else m_btnrestar.colorFondo({0,0,0,0});
		
	}
	if(e.type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2f pos_mouse(e.mouseButton.x,e.mouseButton.y);
		if(calculo_sobreposicion(pos_mouse,vec_botones[0],m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
		{
			m_titulo.setString("Controles");
			m_selectorContenidos=1;
		}
		if(calculo_sobreposicion(pos_mouse,vec_botones[1],m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
		{
			m_titulo.setString("Juego");
			m_selectorContenidos=2;
		}
		if(calculo_sobreposicion(pos_mouse,m_btnsumar,m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
		{
			++(m_configuraciones[0].i_valor);
		}
		if(calculo_sobreposicion(pos_mouse,m_btnrestar,m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
		{
			if(m_configuraciones[0].i_valor>1)
			{
				--(m_configuraciones[0].i_valor);
			}
		}
		if(calculo_sobreposicion(pos_mouse,vec_botones[2],m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
		{
			switch(m_selectorContenidos)
			{
			case 1:
				actualizarTextoControles(stringControles,m_controlesActuales,textos_controles);
				m_settings.actualizarControles(m_controlesActuales);
				m_avisoGuardadoCtrl.setFillColor({0,255,0});
				m_avisoGuardadoCtrl.setString("<Guardado>");
				break;
			case 2:
				m_settings.actualizarConfiguracion(m_configuraciones);
				m_avisoGuardadoJuego.setFillColor({0,255,0});
				m_avisoGuardadoJuego.setString("<Guardado>");
				break;
			}
		}
		for(int i=0;i<selec_cambiosCtrl.size();i++) 
		{
			if(calculo_sobreposicion(pos_mouse,selec_cambiosCtrl[i],m_escalas[0],m_escalas[1]) && e.mouseButton.button == sf::Mouse::Left)
			{
				string x = m_textoEntrada.getValue();
				m_controlesActuales[i] = x;
				actualizarTextoControles(stringControles,m_controlesActuales,textos_controles);
			}
		}
	}
	if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Escape)
	{
		j.CambiarEscena(new PantallaInicio);
	}
}

