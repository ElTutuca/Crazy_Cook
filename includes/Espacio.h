#ifndef ESPACIO_H
#define ESPACIO_H

#include "Definiciones.h"
#include <SFML/Graphics.hpp>

class Espacio {
private:
    sf::Vector2i posicion;
    TileType tipo;

    sf::Vector2i sizeTile;

public:
    Espacio(sf::Vector2i pos, int rot);
    Espacio();
    ~Espacio();

    void setPosicion(sf::Vector2i pos);
    sf::Vector2i getPosicion();

    sf::Vector2f getCoordenadas();

    void setRotacion(int rot);
    int getRotacion();

    void setSizeTile(sf::Vector2i size);
    sf::Vector2i getSizeTile();

    TileType getTipo();

    bool IsColisionando(int x, int y, int ancho, int alto);

    void dibujar(sf::RenderWindow *w);

    // Solo las clases hijas lo pueden ver
    // https://www.wikiwand.com/es/Herencia_(inform%C3%A1tica)
    // Sin herencia las clases Suelo, mesa, hornalla se iban a complicar DEMASIADO
protected:
    sf::Sprite spt;
    int offsetX, offsetY;
    int rotacion;

    bool dibujable;

    void setTipo(TileType t);
};

#endif // ESPACIO_H
