#include "../includes/Suelo.h"
#include "../includes/Definiciones.h"

Suelo::Suelo(sf::Vector2i pos, int rot, sf::Vector2f size) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Suelo);
    setSizeTile(size);
    rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2 + offsetX, getPosicion().y * getSizeTile().y + getSizeTile().y / 2 + offsetY);
    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::Green);
        rectShape.setOutlineThickness(0.5);
        rectShape.setFillColor(sf::Color::Transparent);
    }
}
