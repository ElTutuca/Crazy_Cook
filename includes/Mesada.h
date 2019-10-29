#ifndef MESADA_H
#define MESADA_H
#include "Espacio.h"

class Mesada : public Espacio {
public:
    Mesada(sf::Vector2i pos, int rot, sf::Vector2f size);
    ~Mesada();
    bool putAgarrable(Agarrable *ag);
    Agarrable *popAgarrable();
    Agarrable *getAgarrable();
    void dibujar(sf::RenderWindow *w) override;

protected:
    Agarrable *item;
};

#endif // MESADA_H