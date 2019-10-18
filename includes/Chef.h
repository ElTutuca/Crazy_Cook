#ifndef CHEF_H
#define CHEF_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Chef {
private:
    int x;
    int y;
    int velX;
    int velY;
    float vuelta;
    int ancho;
    int alto;
    float angle;
    Sprite spt;

public:
    Chef(Texture *tex, int x, int y);

    void mover();

    void dibujar(RenderWindow *w);

    void arriba();

    void abajo();

    void girar(char dire);

    // Agregadas

    float getRot();

    int getMedioX();

    int getY();
};

#endif // CHEF_H