#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include "Definiciones.h"
#include "../includes/Espacio.h"
#include "../includes/Mapa.h"
#include <cmath>
#include <SFML/Graphics.hpp>

class Ingrediente {
private:
     sf::Vector2u tamanioReal;
    sf::Vector2f posicion;
    sf::Sprite spt;
    IngredienteType tipo;

public:
    Ingrediente(IngredienteType tipo, sf::Texture *tex);
    IngredienteType getIngredienteType();
    void dibujar(sf::RenderWindow *w);
    void agarrado(int x , int y, float angulo);
};

#endif // INGREDIENTE_H
