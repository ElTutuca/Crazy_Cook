#include "../includes/Mesada.h"

Mesada::Mesada(sf::Vector2i pos, int rot, sf::Vector2i size) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Mesada);
    setSizeTile(size);
}
Mesada::~Mesada() {
}

bool Mesada::ponerOSacarPlato() {
    // TODO: Hacer logica luego de tener el plato
    return false;
}