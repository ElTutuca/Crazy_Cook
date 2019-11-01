#ifndef CLIENTE_H
#define CLIENTE_H

#include <SFML/Graphics.hpp>

class Cliente {
private:
	sf::Clock dtTranscurrido;
	/*variable, depende del pedido*/
	int tiempoEspera;
	short int humor;
	sf::Sprite sCliente;
	
public:
	/*Se va a enviar el pedido y tiempoEspera por el constructor?*/
	Cliente(sf::Vector2f pos, sf::Texture *tCliente);
	~Cliente();
	void actualizarHumor();
	void dibujar(sf::RenderWindow *w);
	/*comprobar si se le fue entregado al cliente su pedido*/
	bool RecibioPedido();
};

#endif
