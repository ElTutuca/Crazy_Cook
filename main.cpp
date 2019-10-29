#include "includes/Button.h"
#include "includes/Chef.h"
#include "includes/Definiciones.h"
#include "includes/Espacio.h"
#include "includes/Mapa.h"
#include "includes/Suelo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

int main() {
    bool jugar = false;

    sf::Font font;
    font.loadFromFile("Fuentes/OpenSans-Light.ttf");

    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    // Vector de vectores
    // niv es el tipo de tiles ordenado en columnas
    std::vector<std::vector<int>> niv = {{1, 3, 3, 1, 1, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};
    // rot es la rotacion de cada tile
    std::vector<std::vector<int>> rot = {{0, 3, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

    Button buttonIniciar(100, 325, 150, 75, "Iniciar Juego", sf::Color::Red, font);
    Button buttonSalir(100, 450, 150, 75, "Salir", sf::Color::Red, font);

    // ? Para que esta esto si el boton ya tiene texto??
    sf::Text textoIniciar;
    textoIniciar.setString("Iniciar");
    textoIniciar.setFont(font);
    textoIniciar.setCharacterSize(40);
    textoIniciar.setOrigin(sf::Vector2f((textoIniciar.getGlobalBounds().width) / 2, (textoIniciar.getGlobalBounds().height) / 2));
    textoIniciar.setPosition(sf::Vector2f(buttonIniciar.getCenterX(), buttonIniciar.getCenterY()));
    textoIniciar.setFillColor(sf::Color::Black);

    sf::Text textoSalir;
    textoSalir.setString("Salir");
    textoSalir.setFont(font);
    textoSalir.setCharacterSize(40);
    textoSalir.setOrigin(sf::Vector2f((textoSalir.getGlobalBounds().width) / 2, (textoSalir.getGlobalBounds().height) / 2));
    textoSalir.setPosition(sf::Vector2f(buttonSalir.getCenterX(), buttonSalir.getCenterY()));
    textoSalir.setFillColor(sf::Color::Black);

    sf::Texture tex, tChef;
    tChef.loadFromFile("Imagenes/Chef.png");
    tex.loadFromFile("Imagenes/Mapa.png");

    //Se crea el mapa y se mandan tipo de tiles y su rotacion, con  la textura del mapa
    Mapa map(niv, rot, &tex);
    Chef chef(&tChef, 200, 200);

    sf::Text debugText;
    sf::Font debugFont;
    if (DEBUGLEVEL == 1) {
        debugFont.loadFromFile("Fuentes/OpenSans-Light.ttf");
        debugText.setFont(font);
        debugText.setCharacterSize(24);
        debugText.setFillColor(sf::Color::Red);
        debugText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }

    // Button button(100, 200, 150, 50, "No implementado", sf::Color::Red);
    window.setFramerateLimit(60);
    sf::Clock dtInteraccion;
    sf::Clock dtCorrer;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (!jugar) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (buttonIniciar.isPressed(&window)) {
                        jugar = true;
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

        bool izq, der, arriba, abajo, interaccion, correr;
        if (jugar) {
            izq = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            der = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
            arriba = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
            abajo = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
            interaccion = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
            correr = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
            chef.mover(izq, der, arriba, abajo, correr, dtCorrer.getElapsedTime());
            chef.interactuar(interaccion, &map, dtInteraccion.getElapsedTime());

            if (interaccion)
                dtInteraccion.restart();
            if (correr)
                dtCorrer.restart();

            map.dibujar(&window);
            chef.dibujar(&window, &map);
        }
        if (DEBUGLEVEL == 1) {
            std::string str = "X: ";
            str.append(std::to_string(sf::Mouse::getPosition(window).x));
            str.append("\n");
            str.append("Y: ");
            str.append(std::to_string(sf::Mouse::getPosition(window).y));
            str.append("\n");
            debugText.setString(str);
            window.draw(debugText);
        }
        window.display();
    }
    return 0;
}
