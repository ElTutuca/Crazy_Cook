#include "includes/Espacio.h"
#include "includes/Mapa.h"
#include "includes/Suelo.h"
#include "includes/Chef.h"
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

    sf::Texture tex,tChef;
    tChef.loadFromFile("Chef.png");
    tex.loadFromFile("resources/Imagenes/Mapa.png");
    Mapa map(niv, rot, &tex);
    Chef chef(&tChef, 640 / 2, 480 / 2);

	//Button button(100,200,150,50,"No implementado",sf::Color::Red);
	
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::MouseButtonPressed)
				//if (button.isPressed(&window))
					//std::cout<<"Boton presionado"<<std::endl;

        window.clear(sf::Color::Green);
        map.dibujar(&window);
		//button.render(&window);
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            chef.girar('i');
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            chef.girar('d');
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            chef.arriba();
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            chef.abajo();
        }



    }
    window.clear(Color(255, 255, 255, 255));
    chef.dibujar(&window);
        window.display();
    }

    return 0;
}
