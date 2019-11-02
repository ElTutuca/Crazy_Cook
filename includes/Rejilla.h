#ifndef REJILLA_H
#define REJILLA_H
#include "Espacio.h"
#include "Plato.h"

class Rejilla : public Espacio {
private:
    sf::Texture texPlato;

public:
    Rejilla(sf::Vector2i pos, int rot, sf::Vector2f size);
    ~Rejilla();
    Plato *getPlato();
};

#endif