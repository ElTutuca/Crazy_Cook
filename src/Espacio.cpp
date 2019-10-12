#include "../includes/Espacio.h"
#include <iostream>

Espacio::Espacio(sf::Vector2i pos, int rot) {
    posicion = pos;
    if (rot >= 0 && rot <= 3)
        rotacion = rot;
    else
        rotacion = 0;
    offsetX = 0;
    offsetY = 0;
    spt.setScale(2, 2);
}
Espacio::Espacio() {
}
Espacio::~Espacio() {
}

void Espacio::setPosicion(sf::Vector2i pos) {
    posicion = pos;
}
sf::Vector2i Espacio::getPosicion() {
    return posicion;
}

void Espacio::setRotacion(int rot) {
    rotacion = rot;
}
int Espacio::getRotacion() {
    return rotacion;
}
void Espacio::dibujar(sf::RenderWindow *w) {
    w->draw(spt);
}