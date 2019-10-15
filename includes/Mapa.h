#ifndef MAPA_H
#define MAPA_H

#include "Espacio.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Mapa {
private:
    std::vector<std::vector<int>> nivel;
    std::vector<std::vector<int>> rotacion;

    std::vector<std::vector<Espacio *>> espacios;

    sf::Sprite fondo;

public:
    Mapa(std::vector<std::vector<int>> niv, std::vector<std::vector<int>> rot, sf::Texture *tMapa);
    ~Mapa();
    void dibujar(sf::RenderWindow *w);
    Espacio *getEspacioAt(int x, int y);
    void setLayout(std::vector<std::vector<int>> niv, std::vector<std::vector<int>> rot);
};

#endif // MAPA_H
