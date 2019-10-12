
#ifndef SUELO_H
#define SUELO_H
#include "Espacio.h"
#include <SFML/Graphics.hpp>

class Suelo : public Espacio {
public:
    Suelo(sf::Vector2i pos, int rot, sf::Texture *tex);
    void dibujar(sf::RenderWindow *w);
};

#endif // SUELO_H
