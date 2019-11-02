#include "../includes/Rejilla.h"
#include <SFML/Graphics.hpp>

Rejilla::Rejilla(sf::Vector2i pos, int rot, sf::Vector2f size) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Rejilla);
    setSizeTile(size);
    texPlato.loadFromFile("Imagenes/Plato.png");

    rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2, getPosicion().y * getSizeTile().y + getSizeTile().y / 2);
    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::Blue);
        rectShape.setOutlineThickness(1);
        rectShape.setFillColor(sf::Color::Transparent);
    }
}
Rejilla::~Rejilla() {
}
Plato *Rejilla::getPlato() {
    return new Plato(sf::Vector2f(0, 0), 0, &texPlato);
}