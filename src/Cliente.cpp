#include "../includes/Cliente.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/*Se va a enviar el pedido y tiempoEspera por el constructor?*/
Cliente::Cliente(sf::Vector2f pos, sf::Texture *tCliente){
	sCliente.setTexture(*tCliente);
	sCliente.setPosition(pos);
	
	dtTranscurrido.restart();
}

Cliente::~Cliente(){
}

/*0: Feliz - 1: Contento - 2: Nada - 3: Descontento - 4: Enojado*/
void Cliente::actualizarHumor(){
	if(dtTranscurrido.getElapsedTime().asMilliseconds() < this->tiempoEspera/4) {
		this->humor=0;
	} else if (dtTranscurrido.getElapsedTime().asMilliseconds() > this->tiempoEspera/4 
			   && dtTranscurrido.getElapsedTime().asMilliseconds() < this->tiempoEspera/2) {
		this->humor=1;
	} else if (dtTranscurrido.getElapsedTime().asMilliseconds() > this->tiempoEspera/2 && dtTranscurrido.getElapsedTime().asMilliseconds() < this->tiempoEspera*(3/4)) {
		this->humor=2;
	} else if (dtTranscurrido.getElapsedTime().asMilliseconds() > this->tiempoEspera*(3/4) 
			   && dtTranscurrido.getElapsedTime().asMilliseconds() < this->tiempoEspera) {
		this->humor=3;
	} else if (dtTranscurrido.getElapsedTime().asMilliseconds() > this->tiempoEspera) {
		this->humor=4;
	}
}

void Cliente::dibujar(sf::RenderWindow *w){
	w->draw(this->sCliente);
}
