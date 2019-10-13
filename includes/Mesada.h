#ifndef MESADA_H
#define MESADA_H
#include "Espacio.h"

class Mesada : public Espacio {
private:
public:
    Mesada(sf::Vector2i pos, int rot);
    ~Mesada();
};

#endif // MESADA_H