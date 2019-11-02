#include "../includes/Hornalla.h"

Hornalla::Hornalla(sf::Vector2i pos, int rot, sf::Vector2f size) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Hornalla);
    setSizeTile(size);
    rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2 + offsetX, getPosicion().y * getSizeTile().y + getSizeTile().y / 2 + offsetY);
    item = nullptr;

    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::White);
        rectShape.setOutlineThickness(0.7);
        rectShape.setFillColor(sf::Color::Transparent);
    }
}
Hornalla::~Hornalla() {
}
bool Hornalla::cocinar(Ingrediente *ing) {
    if (ing->getIngredienteType() == IngredienteType::HamburgesaCruda) {
        if (item == nullptr) {
            item = ing;
            item->setPosicion(sf::Vector2f(getPosicion().x * getSizeTile().x + getSizeTile().x / 2, getPosicion().y * getSizeTile().y + getSizeTile().y / 2));
            return true;
        }
        return false;
    }
    return false;
}
Agarrable *Hornalla::popCocinado() {
    Agarrable *r = item;
    if (item != nullptr) {
        item = nullptr;
    }
    return r;
}
void Hornalla::dibujar(sf::RenderWindow *w) {
    if (dibujable || DEBUGLEVEL == 1) {
        w->draw(rectShape);
    }
    if (item != nullptr)
        item->dibujar(w);
}
