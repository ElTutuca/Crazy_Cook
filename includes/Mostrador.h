#ifndef MOSTRADOR_H
#define MOSTRADOR_H
#include "Espacio.h"
#include "ManejadorClientes.h"

class Mostrador : public Espacio {
private:
    ManejadorClientes *manClientes;

public:
    Mostrador(sf::Vector2i pos, int rot, sf::Vector2f size, ManejadorClientes *manCli);
    ~Mostrador();
    bool putAgarrable(Agarrable *ag);
    void dibujar(sf::RenderWindow *w) override;
};

#endif
