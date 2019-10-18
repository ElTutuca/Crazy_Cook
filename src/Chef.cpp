//
// Created by martin on 13/9/19.
//

#include "Chef.h"
#define degToRad(angleInDegrees) ((angleInDegrees)*M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians)*180.0 / M_PI)

Chef::Chef(Texture *tex, int x, int y) {
    spt.setTexture(*tex);
    ancho = tex->getSize().x;
    alto = tex->getSize().y;

    this->x = x;
    this->y = y;
    angle=0;
    velX = 0;
    velY = 0;
}

void Chef::dibujar(RenderWindow *w) {
    spt.setPosition(x, y);
    w->draw(spt);
}

void Chef::arriba() {

 y -= 5;
 spt.setRotation(180);
    spt.setOrigin(24/2,22/2);
}

void Chef::abajo() {
    y += 5;
    spt.setRotation(0);
    spt.setOrigin(24/2,22/2);
}

void Chef::girar(char dire) {

    if (dire == 'i'){
        x += -5;
        spt.setRotation(90);
        spt.setOrigin(24/2,22/2);}

    else if (dire == 'd') {

      x += 5;
        spt.setRotation(270);
        spt.setOrigin(24/2,22/2);;
    }
}

int Chef::getMedioX() {
    return x + ancho / 2;
}

int Chef::getY() {
    return y;
}

float Chef::getRot(){
    return spt.getRotation();

}
