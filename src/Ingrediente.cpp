#include "../includes/Ingrediente.h"
#include "../includes/Definiciones.h"

Ingrediente::Ingrediente(IngredienteType tipo, sf::Texture *tex) {
    this->tipo = tipo;
    spt.setTexture(*tex);
}

IngredienteType Ingrediente::getIngredienteType() {
    return tipo;
}

void Ingrediente::dibujar(sf::RenderWindow *w) {
    w->draw(spt);
}