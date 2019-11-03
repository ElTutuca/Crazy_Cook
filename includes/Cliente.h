#ifndef CLIENTE_H
#define CLIENTE_H

#include <SFML/Graphics.hpp>
#include "../includes/Plato.h"

class Cliente {
private:
	sf::Clock dtTranscurrido;
	/*variable, depende del pedido*/
	int tiempoEspera;
	Plato orden;
	sf::Sprite sCliente;
	sf::Text humor;
	
public:
	Cliente(sf::Vector2f pos, sf::Texture *tCliente, Plato pedido, int tiempoEspera);
	~Cliente();
	void actualizarHumor();
	void dibujar(sf::RenderWindow *w);
	bool RecibioPedido(Plato *entregado);
};

#endif
