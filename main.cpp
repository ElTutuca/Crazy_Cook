#include "includes/Espacio.h"
#include "includes/Mapa.h"
#include "includes/Suelo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "includes/Button.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    // Vector de vectores
    // niv es el nivel
    std::vector<std::vector<int>> niv = {{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};
    // rot es la rotacion de cada tile
    std::vector<std::vector<int>> rot = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

    sf::Texture tex;
    tex.loadFromFile("resources/Imagenes/Mapa.png");
    Mapa map(niv, rot, &tex);

	//Button button(100,200,150,50,"No implementado",sf::Color::Red);
	
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::MouseButtonPressed)
				//if (button.isPressed(&window))
					//std::cout<<"Boton presionado"<<std::endl;
        }
        window.clear(sf::Color::Green);
        map.dibujar(&window);
		//button.render(&window);
        window.display();
    }

    return 0;
}
