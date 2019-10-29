#include "../includes/Heladera.h"

Heladera::Heladera(sf::Vector2i pos, int rot, sf::Vector2f size, Ingrediente *ingred) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Heladera);
    setSizeTile(size);
    ingrediente = ingred;
    ingrediente->setPosicion(sf::Vector2f(getPosicion().x * getSizeTile().x + getSizeTile().x / 2, getPosicion().y * getSizeTile().y + getSizeTile().y / 2));

    rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2, getPosicion().y * getSizeTile().y + getSizeTile().y / 2);
    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::Cyan);
        rectShape.setOutlineThickness(1);
        rectShape.setFillColor(sf::Color::Transparent);
    }
}
Ingrediente *Heladera::getIngrediente() {
    Ingrediente *r = new Ingrediente(*ingrediente);
    return r;
}

void Heladera::dibujar(sf::RenderWindow *w) {
    if (dibujable || DEBUGLEVEL == 1) {
        w->draw(rectShape);
    }
    if (ingrediente != nullptr)
        ingrediente->dibujar(w);
}