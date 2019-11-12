#ifndef ESPACIO_H
#define ESPACIO_H
#include "Agarrable.h"
#include "Definiciones.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Espacio {
private:
    // Posicion en el arreglo de espacios
    sf::Vector2i posicion;
    TileType tipo;
    sf::Vector2f sizeTile;

public:
    Espacio(sf::Vector2i pos, int rot);
    Espacio();
    ~Espacio();
    void setPosicion(sf::Vector2i pos);
    sf::Vector2i getPosicion();
    sf::Vector2f getSizeTile();
    TileType getTipo();
    virtual void dibujar(sf::RenderWindow *w);
    bool IsColisionando(sf::RectangleShape chef);
    bool IsColisionando(sf::RectangleShape chef, sf::Vector2f *correccion, int dir);
    // Solo las clases hijas lo pueden ver
    // https://www.wikiwand.com/es/Herencia_(inform%C3%A1tica)
    // Sin herencia las clases Suelo, mesa, hornalla se iban a complicar DEMASIADO
protected:
    sf::RectangleShape rectShape;
    // Para los agarrables
    int offsetX, offsetY;
    int rotacion;
    bool dibujable;
    void setTipo(TileType t);
    void setSizeTile(sf::Vector2f size);
};

#endif // ESPACIO_H
