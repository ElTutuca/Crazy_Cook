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
void Espacio::setTipo(TileType t) {
    tipo = t;
}
TileType Espacio::getTipo() {
    return tipo;
}
bool Espacio::IsColisionando(sf::RectangleShape chef) {
    return tipo == TileType::Suelo ? false : rectShape.getGlobalBounds().intersects(chef.getGlobalBounds());
}

bool Espacio::IsColisionando(sf::RectangleShape chef, sf::Vector2f *correccion, int dir) {
    bool colision = this->IsColisionando(chef);
    if (colision) {
        sf::Transform transformacion = chef.getTransform();
        sf::Vector2f p1 = transformacion.transformPoint(chef.getPoint(0));
        sf::Vector2f p2 = transformacion.transformPoint(chef.getPoint(1));
        sf::Vector2f p3 = transformacion.transformPoint(chef.getPoint(2));
        sf::Vector2f p4 = transformacion.transformPoint(chef.getPoint(3));
        sf::Vector2f puntos[4] = {p1, p2, p3, p4};

        float posXEspacio = rectShape.getPosition().x;
        float posYEspacio = rectShape.getPosition().y;
        float mitadXEspacio = rectShape.getSize().x / 2;
        float mitadYEspacio = rectShape.getSize().y / 2;

        for (int i = 0; i < 4; i++) {
            float corrX = 0, corrY = 0;
            if ((puntos[i].x <= (posXEspacio + mitadXEspacio) && puntos[i].x >= (posXEspacio - mitadXEspacio)) && (puntos[i].y <= (posYEspacio + mitadYEspacio) && puntos[i].y >= (posYEspacio - mitadYEspacio))) {
                if (dir == 1) {
                    if (posXEspacio > puntos[i].x) {
                        corrX = (posXEspacio - mitadXEspacio) - puntos[i].x;
                    } else {
                        corrX = (posXEspacio + mitadXEspacio) - puntos[i].x;
                    }
                } else {
                    if (posYEspacio > puntos[i].y) {
                        corrY = (posYEspacio - mitadYEspacio) - puntos[i].y;
                    } else {
                        corrY = (posYEspacio + mitadYEspacio) - puntos[i].y;
                    }
                }
                correccion->x = abs(corrX) > abs(correccion->x) ? corrX : correccion->x;
                correccion->y = abs(corrY) > abs(correccion->y) ? corrY : correccion->y;
            }
        }
    }
    return colision;
}

void Espacio::setSizeTile(sf::Vector2f texSize) {
    sizeTile.x = texSize.x;
    sizeTile.y = texSize.y;
    rectShape.setSize(texSize);
    rectShape.setOrigin(sizeTile.x / 2, sizeTile.y / 2);
}
sf::Vector2f Espacio::getSizeTile() {
    return sizeTile;
}

void Espacio::dibujar(sf::RenderWindow *w) {
    if (dibujable || DEBUGLEVEL == 1)
        w->draw(rectShape);
}
