#include "../includes/Suelo.h"
#include "../includes/Definiciones.h"
#include <iostream>

Suelo::Suelo(sf::Vector2i pos, int rot, sf::Vector2i size) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Suelo);
    setSizeTile(size);
}
