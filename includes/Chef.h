#ifndef CHEF_H
#define CHEF_H
#include "../includes/Definiciones.h"
#include "../includes/Espacio.h"
#include "../includes/Mapa.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Chef {
private:
    float desaceleracion, aceleracionMax, angulo;
    sf::Vector2f posicion;
    sf::Vector2f velocidad;
    sf::Vector2u tamanioReal;
    Sprite spt;

    void actualizar(Mapa *map);
    void actualizarAtributos();
    void actualizarColisiones(Mapa *map);

public:
    Chef(Texture *tex, int x, int y);
    void dibujar(RenderWindow *w, Mapa *map);
    void mover(bool izq, bool der, bool arriba, bool abajo);
};

#endif // CHEF_H