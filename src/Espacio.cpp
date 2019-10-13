#include "../includes/Espacio.h"
#include "../includes/Definiciones.h"
#include <iostream>
#include <math.h>

Espacio::Espacio(sf::Vector2i pos, int rot) {
    posicion = pos;
    if (rot >= 0 && rot <= 3)
        rotacion = rot;
    else
        rotacion = 0;
    offsetX = 0;
    offsetY = 0;
    spt.setScale(SCALE_X, SCALE_Y);
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

void Espacio::setTipo(TileType t) {
    tipo = t;
}
TileType Espacio::getTipo() {
    return tipo;
}

bool Espacio::IsColisionando(int x, int y, int ancho, int alto) {
    // TODO: Hace falta hacer que tome en cuenta el angulo de rotacion del chef
    if (tipo == TileType::Suelo)
        return false;

    bool colisiono = true;

    float anchoMitad = ancho / 2;
    float altoMitad = alto / 2;

    float anchoTileMitad = sizeTile.x / 2;
    float altoTileMitad = sizeTile.y / 2;

    float posX = getPosicion().x * sizeTile.x + anchoTileMitad + offsetX;
    float posY = getPosicion().y * sizeTile.y + altoTileMitad + offsetY;

    // Eje x
    colisiono = colisiono && ((posX + anchoTileMitad) > (x - anchoMitad)) && ((posX - anchoTileMitad) < (x + anchoMitad));

    // Eje y
    colisiono = colisiono && ((posY + altoTileMitad) > (y - anchoMitad)) && ((posY - altoTileMitad) < (x + anchoMitad));

    return colisiono;
}

void Espacio::setSizeTile(sf::Vector2i texSize) {
    sizeTile.x = texSize.x * spt.getScale().x;
    sizeTile.y = texSize.y * spt.getScale().y;
}
sf::Vector2i Espacio::getSizeTile() {
    return sizeTile;
}

void Espacio::dibujar(sf::RenderWindow *w) {
    if (dibujable)
        w->draw(spt);
}