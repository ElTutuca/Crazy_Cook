#include "../includes/Mostrador.h"
#include "../includes/Definiciones.h"
#include "../includes/Ingrediente.h"
#include "../includes/Plato.h"
#include <iostream>

Mostrador::Mostrador(sf::Vector2i pos, int rot, sf::Vector2f size, ManejadorClientes *manCli) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Mostrador);
    setSizeTile(size);
    rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2 + offsetX, getPosicion().y * getSizeTile().y + getSizeTile().y / 2 + offsetY);
    item = nullptr;
    manClientes = manCli;

    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::Black);
        rectShape.setOutlineThickness(0.7);
        rectShape.setFillColor(sf::Color::Transparent);
    }
}

Mostrador::~Mostrador() {
}

bool Mostrador::putAgarrable(Agarrable *ag) {
    if (item == nullptr) {
        manClientes->sendPlato((Plato *)ag);
        delete ag;
        return true;
    }
    return false;
}

Agarrable *Mostrador::popAgarrable() {
    Agarrable *r = item;
    if (item != nullptr) {
        item = nullptr;
    }
    return r;
}

void Mostrador::dibujar(sf::RenderWindow *w) {
    if (dibujable || DEBUGLEVEL == 1) {
        w->draw(rectShape);
    }
    if (item != nullptr)
        item->dibujar(w);
}

Agarrable *Mostrador::getAgarrable() {
    return item;
}
