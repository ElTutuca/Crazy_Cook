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

    Button buttonIniciar(20, 350, 200, 75, sf::Color::Cyan);
    Button buttonSalir(20, 500, 200, 75, sf::Color::Cyan);

    sf::Text textoIniciar;
    textoIniciar.setString("Iniciar");
    textoIniciar.setFont(font);
    textoIniciar.setCharacterSize(40);
    textoIniciar.setOrigin(sf::Vector2f((textoIniciar.getGlobalBounds().width) / 2, (textoIniciar.getGlobalBounds().height) / 2));
    textoIniciar.setPosition(sf::Vector2f(buttonIniciar.getCenterX(), buttonIniciar.getCenterY() - 11));
    textoIniciar.setFillColor(sf::Color::White);

    sf::Text textoSalir;
    textoSalir.setString("Salir");
    textoSalir.setFont(font);
    textoSalir.setCharacterSize(40);
    textoSalir.setOrigin(sf::Vector2f((textoSalir.getGlobalBounds().width) / 2, (textoSalir.getGlobalBounds().height) / 2));
    textoSalir.setPosition(sf::Vector2f(buttonSalir.getCenterX(), buttonSalir.getCenterY() - 11));
    textoSalir.setFillColor(sf::Color::White);

    sf::Texture tex, tChef, menu;
    tChef.loadFromFile("Imagenes/Chef.png");
    tex.loadFromFile("Imagenes/Mapa.png");
    menu.loadFromFile("Imagenes/Menu.jpg");

    sf::Sprite imagenMenu;
    imagenMenu.setTexture(menu);

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
        window.draw(imagenMenu);
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
