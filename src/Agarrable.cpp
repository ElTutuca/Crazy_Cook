#include "../includes/Agarrable.h"
#include "../includes/Definiciones.h"
#include <math.h>

Agarrable::Agarrable() {
}
Agarrable::~Agarrable() {
    // delete spt.getTexture();
}
Agarrable::Agarrable(sf::Vector2f pos, float ang, sf::Texture *tex, bool ingrediente) {
    setPosicion(pos);
    setIsIngrediente(ingrediente);
    angulo = ang;
    spt.setTexture(*tex);
    tamanio.x = tex->getSize().x;
    tamanio.y = tex->getSize().y;
    tamanioReal.x = tamanio.x * SCALE_X;
    tamanioReal.y = tamanio.y * SCALE_Y;
    spt.setScale(SCALE_X, SCALE_Y);
    spt.setOrigin(tamanio.x / 2, tamanio.y / 2);
}
void Agarrable::setPosicion(sf::Vector2f pos) {
    posicion = pos;
}
sf::Vector2f Agarrable::getPosicion() {
    return posicion;
}
float Agarrable::getRotacion() {
    return angulo;
}
bool Agarrable::getIsIngrediente() {
    return isIngrediente;
}
void Agarrable::actualizar() {
    spt.setPosition(posicion);
    spt.setRotation(angulo);
}
void Agarrable::agarrado(int x, int y, float angulo, float anchoChef) {
    this->angulo = angulo;
    posicion.x = x + anchoChef * sin(degToRad(angulo));
    posicion.y = y - anchoChef * cos(degToRad(angulo));
}
void Agarrable::dibujar(sf::RenderWindow *w) {
    actualizar();
    w->draw(spt);
}

void Agarrable::setIsIngrediente(bool t) {
    isIngrediente = t;
}