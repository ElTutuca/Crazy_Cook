#include "includes/Espacio.h"
#include "includes/Mapa.h"
#include "includes/Suelo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    // Vector de vectores
    // niv es el nivel
    std::vector<std::vector<int>> niv = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    // rot es la rotacion de cada tile
    std::vector<std::vector<int>> rot = {{0, 1, 2, 3}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    sf::Texture tex;
    tex.loadFromFile("resources/Imagenes/Mapa.png");
    Mapa map(niv, rot, &tex);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Green);
        map.dibujar(&window);
        window.display();
    }

    return 0;
}