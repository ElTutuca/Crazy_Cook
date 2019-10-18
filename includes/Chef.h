#ifndef AUTO_H
#define AUTO_H
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>



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


#endif //AUTO_H
