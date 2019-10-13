
#ifndef SUELO_H
#define SUELO_H
#include "Espacio.h"

class Suelo : public Espacio {
public:
    Suelo(sf::Vector2i pos, int rot);
};

#endif // SUELO_H
