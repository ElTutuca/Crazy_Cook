#include "../includes/Cliente.h"
#include "../includes/Plato.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>

Cliente::Cliente(sf::Vector2f pos, sf::Texture *tCliente, Plato pedido, int tiempo) {
	sCliente.setTexture(*tCliente);
	sCliente.setPosition(pos);
	
	orden=pedido;
	
	dtTranscurrido.restart();
	
	tiempoEspera=tiempo;
	
	sf::Font font;
	font.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
	this->humor.setString("Feliz");
	this->humor.setFont(font);
	this->humor.setCharacterSize(30);
	this->humor.setOrigin(sf::Vector2f((humor.getGlobalBounds().width) / 2, (humor.getGlobalBounds().height) / 2));
	//this->humor.setPosition(sf::Vector2f(,));
	this->humor.setFillColor(sf::Color::White);
}

Cliente::~Cliente(){
}

/*0: Feliz - 1: Contento - 2: Normal - 3: Descontento - 4: Enojado*/
void Cliente::actualizarHumor(){
	if(dtTranscurrido.getElapsedTime().asMilliseconds() < this->tiempoEspera/4) {
		this->humor.setString("Feliz");
	} else if (dtTranscurrido.getElapsedTime().asMilliseconds() > this->tiempoEspera/4 
			   && dtTranscurrido.getElapsedTime().asMilliseconds() < this->tiempoEspera/2) {
		this->humor.setString("Contento");
	} else if (dtTranscurrido.getElapsedTime().asMilliseconds() > this->tiempoEspera/2 && dtTranscurrido.getElapsedTime().asMilliseconds() < this->tiempoEspera*(3/4)) {
		this->humor.setString("Normal");
	} else if (dtTranscurrido.getElapsedTime().asMilliseconds() > this->tiempoEspera*(3/4) 
			   && dtTranscurrido.getElapsedTime().asMilliseconds() < this->tiempoEspera) {
		this->humor.setString("Descontento");
	} else if (dtTranscurrido.getElapsedTime().asMilliseconds() > this->tiempoEspera) {
		this->humor.setString("Enojado");
	}
}

void Cliente::dibujar(sf::RenderWindow *w){
	w->draw(this->sCliente);
	w->draw(this->humor);
}

bool Cliente::RecibioPedido(Plato *entregado) {
	if(orden==*entregado)
		return true;
	return false;
}

