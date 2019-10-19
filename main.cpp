#include "includes/Button.h"
#include "includes/Chef.h"
#include "includes/Espacio.h"
#include "includes/Mapa.h"
#include "includes/Suelo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    // Vector de vectores
    // niv es el nivel
    std::vector<std::vector<int>> niv = {{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};
    // rot es la rotacion de cada tile
    std::vector<std::vector<int>> rot = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

    sf::Texture tex, tChef;
    tChef.loadFromFile("Imagenes/Chef.png");
    tex.loadFromFile("Imagenes/Mapa.png");
    Mapa map(niv, rot, &tex);
    Chef chef(&tChef, 640 / 2 + 300, 480 / 2);

    // Button button(100, 200, 150, 50, "No implementado", sf::Color::Red);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // if (event.type == sf::Event::MouseButtonPressed)
            //     if (button.isPressed(&window))
            //         std::cout << "Boton presionado" << std::endl;
        }
        window.clear(sf::Color::Green);
        map.dibujar(&window);
        // button.render(&window);
        bool izq, der, arriba, abajo;
        izq = Keyboard::isKeyPressed(Keyboard::Left);
        der = Keyboard::isKeyPressed(Keyboard::Right);
        arriba = Keyboard::isKeyPressed(Keyboard::Up);
        abajo = Keyboard::isKeyPressed(Keyboard::Down);
        chef.mover(izq, der, arriba, abajo);

        chef.dibujar(&window, &map);
        window.display();
    }

    return 0;
}
