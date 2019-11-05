#ifndef HORNALLA_H
#define HORNALLA_H
#include "Espacio.h"
#include "../includes/Definiciones.h"
#include "../includes/Ingrediente.h"
class Hornalla : public Espacio {
public:
	Hornalla(sf::Vector2i pos, int rot, sf::Vector2f size);
	~Hornalla();
	sf::Texture texPrendida;
	void coccion();
	bool cocinar(Ingrediente *ing);
	Agarrable *popCocinado();
	Agarrable *getAgarrable();
	void dibujar(sf::RenderWindow *w) override;
	sf::Clock dtCocinar;
	int tiempoCoccion=5000;
	
protected:
	Agarrable *item;
};

#endif //HORNALLA_H
