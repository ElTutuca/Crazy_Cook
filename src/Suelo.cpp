#include "../includes/Suelo.h"
#include <iostream>

Suelo::Suelo(sf::Vector2i pos, int rot) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(0);
}
