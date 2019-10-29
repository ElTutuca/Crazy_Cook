#include "../includes/Heladera.h"

Heladera::Heladera(sf::Vector2i pos, int rot, sf::Vector2f size, IngredienteType ingrediente) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Heladera);
    setSizeTile(size);

    rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2 + offsetX, getPosicion().y * getSizeTile().y + getSizeTile().y / 2 + offsetY);
    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::Cyan);
        rectShape.setOutlineThickness(1);
        rectShape.setFillColor(sf::Color::Transparent);
    }
}