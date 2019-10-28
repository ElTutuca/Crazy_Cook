#include "../includes/Mesada.h"
#include "../includes/Definiciones.h"

Mesada::Mesada(sf::Vector2i pos, int rot, sf::Vector2f size) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Mesada);
    setSizeTile(size);
    rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2 + offsetX, getPosicion().y * getSizeTile().y + getSizeTile().y / 2 + offsetY);

    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::Magenta);
        rectShape.setOutlineThickness(1);
        rectShape.setFillColor(sf::Color::Transparent);
    }
}
Mesada::~Mesada() {
}

bool Mesada::ponerOSacarPlato() {
    // TODO: Hacer logica luego de tener el plato
    return false;
}