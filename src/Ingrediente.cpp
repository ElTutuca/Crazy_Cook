#include "../includes/Ingrediente.h"
#include "../includes/Chef.h"
#include "../includes/Definiciones.h"

Ingrediente::Ingrediente(IngredienteType tipo, sf::Texture *tex) {
    spt.setTexture(*tex);
    tamanioReal.x = tex->getSize().x * SCALE_X;
    tamanioReal.y = tex->getSize().y * SCALE_Y;
    this->tipo = tipo;
    spt.setTexture(*tex);
    // ? Que x y que y??
    // posicion.x = x;
    // posicion.y = y;
}

IngredienteType Ingrediente::getIngredienteType() {
    return tipo;
}
void Ingrediente::agarrado(int x, int y, float angulo) {
    posicion.x = x + SEPARACION * sin(angulo);
    posicion.y = y - SEPARACION * cos(angulo);
}

void Ingrediente::dibujar(sf::RenderWindow *w) {
    spt.setPosition(posicion);
    w->draw(spt);
}
