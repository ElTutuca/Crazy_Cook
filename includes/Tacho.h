#ifndef TACHO_H
#define TACHO_H
#include "Espacio.h"

class Tacho : public Espacio {

public:
    Tacho(sf::Vector2i pos, int rot, sf::Vector2f size);
    bool tirar(Agarrable *ag);
};

#endif // TACHO_H
