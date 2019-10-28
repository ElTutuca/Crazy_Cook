#ifndef CHEF_H
#define CHEF_H
#include "../includes/Definiciones.h"
#include "../includes/Mapa.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Chef {
private:
    float desaceleracion, aceleracionMax, angulo;
    sf::RectangleShape rectShape;
    sf::RectangleShape hitbox;
    sf::Vector2f velocidad;
    sf::Vector2u tamanioReal;

    void actualizar(Mapa *map);
    void actualizarAtributos();
    void actualizarColisiones(Mapa *map);

public:
    Chef(Texture *tex, int x, int y);
    void dibujar(RenderWindow *w, Mapa *map);
    void mover(bool izq, bool der, bool arriba, bool abajo);
    sf::RectangleShape getRectangleShape();
    sf::RectangleShape getHitbox();
};

#endif // CHEF_H