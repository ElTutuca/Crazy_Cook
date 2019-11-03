
#include "../includes/Chef.h"
#include "../includes/Definiciones.h"
#include "../includes/Heladera.h"
#include "../includes/Hornalla.h"
#include "../includes/Mesada.h"
#include "../includes/Rejilla.h"
#include "../includes/Tacho.h"
#include "../includes/Mostrador.h"
#include <iostream>
#include <math.h>
#define entreExcluyente(valor, valorMenor, valorMayor) ((valor > valorMenor && valor < valorMayor))
#define entreIncluyente(valor, valorMenor, valorMayor) ((valor >= valorMenor && valor <= valorMayor))

Chef::Chef(sf::Texture *tex, int x, int y) {
    rectShape.setTexture(tex);
    rectShape.setSize(sf::Vector2f(tex->getSize().x, tex->getSize().y));
    rectShape.setOrigin(tex->getSize().x / 2, tex->getSize().y / 2);
    rectShape.setPosition(x, y);

    hitbox.setSize(sf::Vector2f(rectShape.getSize().x / 2, rectShape.getSize().y / 2));
    hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y / 2);
    hitbox.setPosition(x, y);

    enMano = nullptr;

    dtInteraccion.restart();
    dtCorrer.restart();

    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::Yellow);
        rectShape.setOutlineThickness(1);
        hitbox.setOutlineColor(sf::Color::Red);
        hitbox.setOutlineThickness(1);
        hitbox.setFillColor(sf::Color::Transparent);
    }

    velocidad.x = 0;
    velocidad.y = 0;
    velocidadCorrer.x = 0;
    velocidadCorrer.y = 0;
    velocidadCaminar.x = 0;
    velocidadCaminar.y = 0;

    angulo = 0;
    desaceleracionCaminar = 0.9;
    aceleracionCaminar = 0.25;

    desaceleracionCorrer = 0.95;
    aceleracionCorrer = 1;
}

sf::RectangleShape Chef::getRectangleShape() {
    return rectShape;
}

void Chef::actualizar(Mapa *map) {
    actualizarAtributos();
    actualizarColisiones(map);
}

void Chef::actualizarAtributos() {
    velocidadCorrer.x *= desaceleracionCorrer;
    velocidadCorrer.y *= desaceleracionCorrer;
    velocidadCaminar.x *= desaceleracionCaminar;
    velocidadCaminar.y *= desaceleracionCaminar;
    velocidad.x = velocidadCaminar.x + velocidadCorrer.x;
    velocidad.y = velocidadCaminar.y + velocidadCorrer.y;
    rectShape.setPosition(rectShape.getPosition().x + velocidad.x, rectShape.getPosition().y + velocidad.y);
    rectShape.setRotation(angulo);
    hitbox.setPosition(rectShape.getPosition());
    hitbox.setRotation(angulo);
    if (enMano != nullptr) {
        enMano->agarrado(getRectangleShape().getPosition().x, getRectangleShape().getPosition().y, angulo, rectShape.getSize().y);
    }
}

void Chef::actualizarColisiones(Mapa *map) {
    sf::Vector2i posEnArr(rectShape.getPosition().x / (TILEWIDTH), rectShape.getPosition().y / (TILEHEIGHT));
    sf::Vector2f correccion(0, 0);
    bool colisionoArriba, colisionoAbajo, colisionoIzquierda, colisionoDerecha;

    // Celdas adyacentes
    colisionoIzquierda = posEnArr.x > 0 ? map->getEspacioAt(posEnArr.x - 1, posEnArr.y)->IsColisionando(hitbox, &correccion, 1) : false;
    colisionoDerecha = posEnArr.x < map->getAncho() ? map->getEspacioAt(posEnArr.x + 1, posEnArr.y)->IsColisionando(hitbox, &correccion, 1) : false;
    colisionoArriba = posEnArr.y > 0 ? map->getEspacioAt(posEnArr.x, posEnArr.y - 1)->IsColisionando(hitbox, &correccion, 0) : false;
    colisionoAbajo = posEnArr.y < map->getAlto() ? map->getEspacioAt(posEnArr.x, posEnArr.y + 1)->IsColisionando(hitbox, &correccion, 0) : false;

    // Resolucion ante colision
    if (correccion.x != 0 || correccion.y != 0) {
        float x = rectShape.getPosition().x + correccion.x;
        float y = rectShape.getPosition().y + correccion.y;
        rectShape.setPosition(x, y);
        hitbox.setPosition(x, y);
        if (correccion.x != 0) {
            velocidad.x = 0;
        } else if (correccion.y != 0) {
            velocidad.y = 0;
        }
    }
}

void Chef::dibujar(sf::RenderWindow *w, Mapa *map) {
    actualizar(map);
    w->draw(rectShape);
    if (enMano != nullptr)
        enMano->dibujar(w);

    if (DEBUGLEVEL == 1) {
        w->draw(hitbox);
    }
}

void Chef::mover(bool izq, bool der, bool arriba, bool abajo, bool correr) {
    bool hacerCorrer = correr && dtCorrer.getElapsedTime().asMilliseconds() > 500;
    if (izq && !der) {
        if (arriba) {
            angulo = 315;
            // sqrt(2) / 2 = cos(45)
            if (hacerCorrer) {
                velocidadCorrer.x -= (sqrt(2) / 2) * aceleracionCorrer;
                velocidadCorrer.y -= (sqrt(2) / 2) * aceleracionCorrer;
            }
            velocidadCaminar.x -= (sqrt(2) / 2) * aceleracionCaminar;
            velocidadCaminar.y -= (sqrt(2) / 2) * aceleracionCaminar;
        } else if (abajo) {
            angulo = 225;
            if (hacerCorrer) {
                velocidadCorrer.x -= (sqrt(2) / 2) * aceleracionCorrer;
                velocidadCorrer.y += (sqrt(2) / 2) * aceleracionCorrer;
            }
            velocidadCaminar.x -= (sqrt(2) / 2) * aceleracionCaminar;
            velocidadCaminar.y += (sqrt(2) / 2) * aceleracionCaminar;
        } else {
            angulo = 270;
            if (hacerCorrer)
                velocidadCorrer.x -= aceleracionCorrer;
            velocidadCaminar.x -= aceleracionCaminar;
        }
    } else if (der && !izq) {
        if (arriba) {
            angulo = 45;
            if (hacerCorrer) {
                velocidadCorrer.x += (sqrt(2) / 2) * aceleracionCorrer;
                velocidadCorrer.y -= (sqrt(2) / 2) * aceleracionCorrer;
            }
            velocidadCaminar.x += (sqrt(2) / 2) * aceleracionCaminar;
            velocidadCaminar.y -= (sqrt(2) / 2) * aceleracionCaminar;
        } else if (abajo) {
            angulo = 135;
            if (hacerCorrer) {
                velocidadCorrer.x += (sqrt(2) / 2) * aceleracionCorrer;
                velocidadCorrer.y += (sqrt(2) / 2) * aceleracionCorrer;
            }
            velocidadCaminar.x += (sqrt(2) / 2) * aceleracionCaminar;
            velocidadCaminar.y += (sqrt(2) / 2) * aceleracionCaminar;
        } else {
            angulo = 90;
            if (hacerCorrer)
                velocidadCorrer.x += aceleracionCorrer;
            velocidadCaminar.x += aceleracionCaminar;
        }
    } else if (arriba && !abajo) {
        angulo = 0;
        if (hacerCorrer)
            velocidadCorrer.y -= aceleracionCorrer;
        velocidadCaminar.y -= aceleracionCaminar;
    } else if (abajo && !arriba) {
        angulo = 180;
        if (hacerCorrer)
            velocidadCorrer.y += aceleracionCorrer;
        velocidadCaminar.y += aceleracionCaminar;
    }
    if (hacerCorrer)
        dtCorrer.restart();
}

void Chef::interactuar(bool interactuar, Mapa *map) {
    sf::Vector2i posEnArr(rectShape.getPosition().x / TILEWIDTH, rectShape.getPosition().y / TILEHEIGHT);
    if (interactuar && dtInteraccion.getElapsedTime().asMilliseconds() > 80) {
        // Mira hacia arriba
        Espacio *es = nullptr;
        if (angulo == 0) {
            es = map->getEspacioAt(posEnArr.x, posEnArr.y - 1);
        } else if (angulo == 180) {
            es = map->getEspacioAt(posEnArr.x, posEnArr.y + 1);
        } else if (angulo == 270) {
            es = map->getEspacioAt(posEnArr.x - 1, posEnArr.y);
        } else if (angulo == 90) {
            es = map->getEspacioAt(posEnArr.x + 1, posEnArr.y);
        }
        if (es != nullptr) {
            if (es->getTipo() == TileType::Heladera) {
                class Heladera *h = (class Heladera *)es;
                if (enMano == nullptr) {
                    enMano = h->getIngrediente();
                }
            } else if (es->getTipo() == TileType::Mesada) {
                class Mesada *m = (class Mesada *)es;
                if (enMano == nullptr) {
                    Agarrable *r = m->popAgarrable();
                    if (r != nullptr) {
                        enMano = r;
                    }
                } else {
                    bool r = m->putAgarrable(enMano);
                    enMano = r ? nullptr : enMano;
                }
            } else if (es->getTipo() == TileType::Tacho) {
                class Tacho *m = (class Tacho *)es;
                if (enMano != nullptr) {
                    bool r = m->tirar(enMano);
                    enMano = r ? nullptr : enMano;
                }
            } else if (es->getTipo() == TileType::Hornalla) {
                class Hornalla *m = (class Hornalla *)es;
                if (enMano == nullptr) {
                    Agarrable *r = m->popCocinado();
                    if (r != nullptr) {
                        enMano = r;
                    }
                } else if (enMano->getIsIngrediente()) {
                    bool r = m->cocinar((Ingrediente *)enMano);
                    enMano = r ? nullptr : enMano;
                }
            } else if (es->getTipo() == TileType::Rejilla) {
                class Rejilla *m = (class Rejilla *)es;
                if (enMano == nullptr) {
                    enMano = (Agarrable *)m->getPlato();
                }
            } else if (es->getTipo() == TileType::Mostrador) {
				class Mostrador *m = (class Mostrador *)es;
				if (enMano == nullptr) {
					Agarrable *r = m->popAgarrable();
					if (r != nullptr) {
						enMano = r;
					}
				} else {
					bool r = m->putAgarrable(enMano);
					enMano = r ? nullptr : enMano;
				}
			} 
        }
    }
    if (interactuar)
        dtInteraccion.restart();
}
