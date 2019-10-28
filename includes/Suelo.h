
#ifndef SUELO_H
#define SUELO_H
#include "Espacio.h"

class Suelo : public Espacio {
public:
    Suelo(sf::Vector2i pos, int rot, sf::Vector2f size);
};

#endif // SUELO_H
