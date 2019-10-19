
#include "../includes/Chef.h"
#include "../includes/Definiciones.h"
#include <iostream>
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees)*M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians)*180.0 / M_PI)
#define entreExcluyente(valor, valorMenor, valorMayor) ((valor > valorMenor && valor < valorMayor))
#define entreIncluyente(valor, valorMenor, valorMayor) ((valor >= valorMenor && valor <= valorMayor))

Chef::Chef(Texture *tex, int x, int y) {
    spt.setTexture(*tex);
    tamanioReal.x = tex->getSize().x * SCALE_X;
    tamanioReal.y = tex->getSize().y * SCALE_Y;
    spt.setOrigin(tex->getSize().x / 2, tex->getSize().y / 2);
    spt.setScale(SCALE_X, SCALE_Y);

    posicion.x = x;
    posicion.y = y;
    velocidad.x = 0;
    velocidad.y = 0;

    angulo = 0;
    desaceleracion = 0.9;
    aceleracionMax = 0.82;
}

void Chef::actualizar(Mapa *map) {
    actualizarColisiones(map);
}

void Chef::actualizarAtributos() {
    posicion.x += velocidad.x;
    posicion.y += velocidad.y;
    velocidad.x *= desaceleracion;
    velocidad.y *= desaceleracion;
}

void Chef::actualizarColisiones(Mapa *map) {
    sf::Vector2i posEnArr(posicion.x / (TILEWIDTH * SCALE_X), posicion.y / (TILEHEIGHT * SCALE_Y));
    bool colisionoArriba, colisionoAbajo, colisionoIzquierda, colisionoDerecha;

    // Posibilidades de colision en el eje x
    if (posEnArr.x > 0 && posEnArr.x < map->getAncho()) {
        colisionoIzquierda = map->getEspacioAt(posEnArr.x - 1, posEnArr.y)->IsColisionando(posicion.x, posicion.y, tamanioReal.x, tamanioReal.y);
        colisionoDerecha = map->getEspacioAt(posEnArr.x + 1, posEnArr.y)->IsColisionando(posicion.x, posicion.y, tamanioReal.x, tamanioReal.y);
    } else if (posEnArr.x == 0) {
        colisionoIzquierda = true;
        colisionoDerecha = map->getEspacioAt(posEnArr.x + 1, posEnArr.y)->IsColisionando(posicion.x, posicion.y, tamanioReal.x, tamanioReal.y);
    } else {
        colisionoIzquierda = map->getEspacioAt(posEnArr.x - 1, posEnArr.y)->IsColisionando(posicion.x, posicion.y, tamanioReal.x, tamanioReal.y);
        colisionoDerecha = true;
    }

    // Posibilidades de colision en el eje y
    if (posEnArr.y > 0 && posEnArr.y < map->getAlto()) {
        colisionoArriba = map->getEspacioAt(posEnArr.x, posEnArr.y - 1)->IsColisionando(posicion.x, posicion.y, tamanioReal.x, tamanioReal.y);
        colisionoAbajo = map->getEspacioAt(posEnArr.x, posEnArr.y + 1)->IsColisionando(posicion.x, posicion.y, tamanioReal.x, tamanioReal.y);
    } else if (posEnArr.y == 0) {
        colisionoArriba = true;
        colisionoAbajo = map->getEspacioAt(posEnArr.x, posEnArr.y + 1)->IsColisionando(posicion.x, posicion.y, tamanioReal.x, tamanioReal.y);
    } else {
        colisionoArriba = map->getEspacioAt(posEnArr.x, posEnArr.y - 1)->IsColisionando(posicion.x, posicion.y, tamanioReal.x, tamanioReal.y);
        colisionoAbajo = true;
    }

    // Todo salio bien!
    if ((!colisionoAbajo && !colisionoArriba && !colisionoIzquierda && !colisionoDerecha)) {
        actualizarAtributos();
    } else {
        // Colisiono!
        // Anular velocidad al momento del choque y cuando quiere avanzar hacia el lugar al que esta chocando
        if ((colisionoIzquierda && angulo == 270) || (colisionoDerecha && angulo == 90) || (colisionoArriba && angulo == 0) || (colisionoAbajo && angulo == 180)) {
            velocidad.x = 0;
            velocidad.y = 0;
        } else if (colisionoIzquierda) {
            // Ahora se chequea todos los tipos de colisiones posibles
            if (colisionoArriba) {
                // ? if (!entreExcluyente(angulo, 0, 270)) {
                if (!entreExcluyente(angulo, 270, 360)) {
                    if (entreIncluyente(angulo, 45, 90)) {
                        posicion.x += velocidad.x;
                        velocidad.x *= desaceleracion;
                        velocidad.y = 0;
                    } else if (entreIncluyente(angulo, 180, 225)) {
                        posicion.y += velocidad.y;
                        velocidad.y *= desaceleracion;
                        velocidad.x = 0;
                    } else {
                        actualizarAtributos();
                    }
                }
            } else if (colisionoAbajo) {
                if (!entreExcluyente(angulo, 180, 270)) {
                    if (entreIncluyente(angulo, 315, 0)) {
                        posicion.x += velocidad.x;
                        velocidad.x *= desaceleracion;
                        velocidad.y = 0;
                    } else if (entreIncluyente(angulo, 90, 135)) {
                        posicion.y += velocidad.y;
                        velocidad.y *= desaceleracion;
                        velocidad.x = 0;
                    } else {
                        actualizarAtributos();
                    }
                }
            } else {
                if (entreIncluyente(angulo, 315, 360) || entreIncluyente(angulo, 180, 225)) {
                    posicion.y += velocidad.y;
                    velocidad.y *= desaceleracion;
                    velocidad.x = 0;
                } else {
                    actualizarAtributos();
                }
            }
        } else if (colisionoDerecha) {
            // Ahora se chequea todos los tipos de colisiones posibles
            if (colisionoArriba) {
                if (!entreExcluyente(angulo, 0, 90)) {
                    if (entreIncluyente(angulo, 270, 315)) {
                        posicion.x += velocidad.x;
                        velocidad.x *= desaceleracion;
                        velocidad.y = 0;
                    } else if (entreIncluyente(angulo, 135, 180)) {
                        posicion.y += velocidad.y;
                        velocidad.y *= desaceleracion;
                        velocidad.x = 0;
                    } else {
                        actualizarAtributos();
                    }
                }
            } else if (colisionoAbajo) {
                if (!entreExcluyente(angulo, 90, 180)) {
                    if (entreIncluyente(angulo, 225, 270)) {
                        posicion.x += velocidad.x;
                        velocidad.x *= desaceleracion;
                        velocidad.y = 0;
                    } else if (entreIncluyente(angulo, 0, 45)) {
                        posicion.y += velocidad.y;
                        velocidad.y *= desaceleracion;
                        velocidad.x = 0;
                    } else {
                        actualizarAtributos();
                    }
                }
            } else {
                // ! Son las mismas condiciones que arriba (en donde se cancela la comp x)
                if (entreIncluyente(angulo, 0, 45) || entreIncluyente(angulo, 135, 180)) {
                    posicion.y += velocidad.y;
                    velocidad.y *= desaceleracion;
                    velocidad.x = 0;
                } else {
                    actualizarAtributos();
                }
            }
        } else if (colisionoArriba) {
            // Ahora se chequea todos los tipos de colisiones posibles
            if (entreIncluyente(angulo, 45, 90) || entreIncluyente(angulo, 270, 315)) {
                posicion.x += velocidad.x;
                velocidad.x *= desaceleracion;
                velocidad.y = 0;
            } else {
                actualizarAtributos();
            }
        } else if (colisionoAbajo) {
            // Ahora se chequea todos los tipos de colisiones posibles
            if (entreIncluyente(angulo, 90, 135) || entreIncluyente(angulo, 225, 270)) {
                posicion.x += velocidad.x;
                velocidad.x *= desaceleracion;
                velocidad.y = 0;
            } else {
                actualizarAtributos();
            }
        }
    }
}

void Chef::dibujar(RenderWindow *w, Mapa *map) {
    actualizar(map);

    spt.setRotation(angulo);
    spt.setPosition(posicion);
    w->draw(spt);
}

void Chef::mover(bool izq, bool der, bool arriba, bool abajo) {
    if (izq && !der) {
        if (arriba) {
            angulo = 315;
            // sqrt(2) / 2 = cos(45)
            velocidad.x -= (sqrt(2) / 2) * aceleracionMax;
            velocidad.y -= (sqrt(2) / 2) * aceleracionMax;
        } else if (abajo) {
            angulo = 225;
            velocidad.x -= (sqrt(2) / 2) * aceleracionMax;
            velocidad.y += (sqrt(2) / 2) * aceleracionMax;
        } else {
            angulo = 270;
            velocidad.x -= aceleracionMax;
        }
    } else if (der && !izq) {
        if (arriba) {
            angulo = 45;
            velocidad.x += (sqrt(2) / 2) * aceleracionMax;
            velocidad.y -= (sqrt(2) / 2) * aceleracionMax;
        } else if (abajo) {
            angulo = 135;
            velocidad.x += (sqrt(2) / 2) * aceleracionMax;
            velocidad.y += (sqrt(2) / 2) * aceleracionMax;
        } else {
            angulo = 90;
            velocidad.x += aceleracionMax;
        }
    } else if (arriba && !abajo) {
        angulo = 0;
        velocidad.y -= aceleracionMax;
    } else if (abajo && !arriba) {
        angulo = 180;
        velocidad.y += aceleracionMax;
    }
}