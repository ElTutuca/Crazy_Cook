#ifndef ESPACIO_H
#define ESPACIO_H

#include <SFML/Graphics.hpp>

class Espacio {
private:
    sf::Vector2i posicion;

    int tipo;

public:
    Espacio(sf::Vector2i pos, int rot);
    Espacio();
    ~Espacio();

    void setPosicion(sf::Vector2i pos);
    sf::Vector2i getPosicion();

    void setRotacion(int rot);
    int getRotacion();

    int getTipo();

    void dibujar(sf::RenderWindow *w);

    // Solo las clases hijas lo pueden ver
    // https://www.wikiwand.com/es/Herencia_(inform%C3%A1tica)
    // Sin herencia las clases Suelo, mesa, hornalla se iban a complicar DEMASIADO
protected:
    sf::Sprite spt;
    int offsetX, offsetY;
    int rotacion;

    bool dibujable;

    void setTipo(int t);
};

#endif // ESPACIO_H
