#ifndef MESADA_H
#define MESADA_H
#include "Espacio.h"

class Mesada : public Espacio {
private:
    // TODO: Plato sobre mesada
public:
    Mesada(sf::Vector2i pos, int rot, sf::Vector2i size);
    ~Mesada();

    bool ponerOSacarPlato();
};

#endif // MESADA_H