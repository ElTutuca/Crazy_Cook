#ifndef ESPACIO_H
#define ESPACIO_H

#include <SFML/Graphics.hpp>

class Espacio {
private:
    sf::Vector2i posicion;

public:
    Espacio(sf::Vector2i pos, int rot);
    Espacio();
    ~Espacio();

    void setPosicion(sf::Vector2i pos);
    sf::Vector2i getPosicion();

    void setRotacion(int rot);
    int getRotacion();

    void dibujar(sf::RenderWindow *w);

    // Solo las clases hijas lo pueden ver
    // https://www.wikiwand.com/es/Herencia_(inform%C3%A1tica)
    // Sin herencia las clases Suelo, mesa, hornalla se iban a complicar DEMASIADO
protected:
    sf::Sprite spt;
    int offsetX, offsetY;
    int rotacion;
};

#endif // ESPACIO_H
