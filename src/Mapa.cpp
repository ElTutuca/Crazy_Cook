#include "../includes/Mapa.h"
#include "../includes/Definiciones.h"
#include "../includes/Espacio.h"
#include "../includes/Mesada.h"
#include "../includes/Suelo.h"
#include "../includes/Heladera.h"
#include <iostream>
#include <vector>

Mapa::Mapa(std::vector<std::vector<int>> niv, std::vector<std::vector<int>> rot, sf::Texture *tMapa) {
    //se inicializa la posicion de los tiles
    setLayout(niv, rot);
    selecIngrediente=Lechuga;
    fondo.setTexture(*tMapa);
    fondo.setScale(SCALE_X, SCALE_Y);

    // assign le da el tamaño al vector
    espacios.assign(nivel.size(), std::vector<Espacio *>(nivel[0].size(), new Espacio()));

    // Le asigna un espacio a cada elemento
    sf::Vector2i texSize(32, 32);
    for (int x = 0; x < nivel.size(); x++) {
        for (int y = 0; y < nivel[x].size(); y++) {
            if (nivel[x][y] == TileType::Suelo) {
                // ? Deberia ser un casteo dinamico??
                //se crea un espacio de tipo suelo
                class Suelo *s = new class Suelo(sf::Vector2i(x, y), rotacion[x][y], texSize);
                espacios[x][y] = (Espacio *)s;
            } else if (nivel[x][y] == TileType::Mesada) {
                // ? Deberia ser un casteo dinamico??
                //se crea un espacio de tipo mesada
                class Mesada *s = new class Mesada(sf::Vector2i(x, y), rotacion[x][y], texSize);
                espacios[x][y] = (Espacio *)s;
                // Asi se castea
                // Espacio *e = (Espacio *)s;
                // class Mesada *r = (class Mesada *)e;
                // std::cout << r->test << std::endl;
            }else if (nivel[x][y] == TileType::Heladera){
                class Heladera *s = new class Heladera(sf::Vector2i(x, y), rotacion[x][y], texSize,selecIngrediente);
                espacios[x][y] = (Espacio *)s;
            }
            //TODO: Resto de los objetos
        }
    }
}

Mapa::~Mapa() {
    for (int x = 0; x < nivel.size(); x++) {
        for (int y = 0; y < nivel[x].size(); y++) {
            delete getEspacioAt(x, y);
        }
    }
}

void Mapa::dibujar(sf::RenderWindow *w) {
    w->draw(fondo);
    for (int x = 0; x < nivel.size(); x++) {
        for (int y = 0; y < nivel[x].size(); y++) {
            getEspacioAt(x, y)->dibujar(w);
        }
    }
}

Espacio *Mapa::getEspacioAt(int x, int y) {
    return espacios[x][y];
}

void Mapa::setLayout(std::vector<std::vector<int>> niv, std::vector<std::vector<int>> rot) {
    nivel = niv;
    rotacion = rot;
}

int Mapa::getAncho() {
    return nivel.size();
}
int Mapa::getAlto() {
    return nivel[0].size();
}