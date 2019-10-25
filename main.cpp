#include "includes/Button.h"
#include "includes/Chef.h"
#include "includes/Espacio.h"
#include "includes/Mapa.h"
#include "includes/Suelo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main() {
	bool jugar=false;
	
	sf::Font font;
	font.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
	
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    // Vector de vectores
    // niv es el tipo de tiles ordenado en columnas
    std::vector<std::vector<int>> niv = {{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};
    // rot es la rotacion de cada tile
    std::vector<std::vector<int>> rot = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

	Button buttonIniciar(100, 325, 150, 75, "Iniciar Juego", sf::Color::Red, font);
	Button buttonSalir(100, 450, 150, 75, "Salir", sf::Color::Red, font);
	
	sf::Text textoIniciar;
	textoIniciar.setString("Iniciar");
	textoIniciar.setFont(font);
	textoIniciar.setCharacterSize(40);
	textoIniciar.setOrigin(sf::Vector2f((textoIniciar.getGlobalBounds().width)/2,(textoIniciar.getGlobalBounds().height)/2));
	textoIniciar.setPosition(sf::Vector2f(buttonIniciar.getCenterX(),buttonIniciar.getCenterY()));
	textoIniciar.setFillColor(sf::Color::Black);
	
	sf::Text textoSalir;
	textoSalir.setString("Salir");
	textoSalir.setFont(font);
	textoSalir.setCharacterSize(40);
	textoSalir.setOrigin(sf::Vector2f((textoSalir.getGlobalBounds().width)/2,(textoSalir.getGlobalBounds().height)/2));
	textoSalir.setPosition(sf::Vector2f(buttonSalir.getCenterX(),buttonSalir.getCenterY()));
	textoSalir.setFillColor(sf::Color::Black);
	
    sf::Texture tex, tChef;
    tChef.loadFromFile("resources/Imagenes/Chef.png");
    tex.loadFromFile("resources/Imagenes/Mapa.png");
	
    //Se crea el mapa y se mandan tipo de tiles y su rotacion, con  la textura del mapa
    Mapa map(niv, rot, &tex);
    Chef chef(&tChef, 640 / 2 + 300, 480 / 2);
    
	window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
			
			if (!jugar){
				if (event.type == sf::Event::MouseButtonPressed) {
					if (buttonIniciar.isPressed(&window)) {
						jugar=true;
					}
					if (buttonSalir.isPressed(&window))
						window.close();
				}
			}
		}
		window.clear(sf::Color::Green);
		buttonIniciar.render(&window);
		buttonSalir.render(&window);
		window.draw(textoIniciar);
		window.draw(textoSalir);
		
        bool izq, der, arriba, abajo;
		if(jugar){
			izq = Keyboard::isKeyPressed(Keyboard::Left);
			der = Keyboard::isKeyPressed(Keyboard::Right);
			arriba = Keyboard::isKeyPressed(Keyboard::Up);
			abajo = Keyboard::isKeyPressed(Keyboard::Down);
			chef.mover(izq, der, arriba, abajo);
			map.dibujar(&window);
			chef.dibujar(&window, &map);
		}
		window.display();
       
    }

    return 0;
}
