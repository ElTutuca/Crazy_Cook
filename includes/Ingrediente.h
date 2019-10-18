#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include "Definiciones.h"
#include <SFML/Graphics.hpp>

class Ingrediente {
private:
    sf::Sprite spt;
    IngredienteType tipo;

public:
    Ingrediente(IngredienteType tipo, sf::Texture *tex);
    IngredienteType getIngredienteType();
    void dibujar(sf::RenderWindow *w);
};

#endif // INGREDIENTE_H