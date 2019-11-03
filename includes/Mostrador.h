#ifndef MOSTRADOR_H
#define MOSTRADOR_H
#include "Espacio.h"

class Mostrador : public Espacio {
public:
	Mostrador(sf::Vector2i pos, int rot, sf::Vector2f size);
	~Mostrador();
	bool putAgarrable(Agarrable *ag);
	Agarrable *popAgarrable();
	Agarrable *getAgarrable();
	void dibujar(sf::RenderWindow *w) override;
	
protected:
	Agarrable *item;
};


#endif
