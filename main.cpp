#include "includes/Button.h"
#include "includes/Chef.h"
#include "includes/Cliente.h"
#include "includes/Definiciones.h"
#include "includes/Espacio.h"
#include "includes/ListaIngredientes.h"
#include "includes/ManejadorClientes.h"
#include "includes/Mapa.h"
#include "includes/Suelo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

float SCALE = 0;
int SCREENWIDTH = 0;
int SCREENHEIGHT = 0;
int MAPWIDTH = 0;
int MAPHEIGHT = 0;
int PANEWIDTH = 60;
const int TILEWIDTH = 32;
const int TILEHEIGHT = 32;
int main() {

    bool jugando = false, finPartida = false, isVistaJuego = false;
    int tiempoDeJuego = 360;
    std::string strTxtBox = "";
    sf::Clock timeInGame;
    std::vector<std::vector<int>> niv = {{1, 3, 3, 3, 3, 1}, {3, 0, 0, 0, 0, 1}, {4, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 1}, {5, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 6, 6, 1, 1}};
    std::vector<std::vector<int>> rot = {{0, 3, 3, 3, 3, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

    SCREENWIDTH = sf::VideoMode::getDesktopMode().width;
    SCREENHEIGHT = sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Crazy Cook");
    window.setFramerateLimit(60);

    sf::Font font;
    sf::Texture tex, tChef, menu;
    sf::Text textoIniciar, textoSalir, txtFin, txtRectTxtBox, txtScoreBoard;
    sf::RectangleShape rectScoreBoard, rectTxtBox;
    tChef.loadFromFile("resources/Imagenes/Chef.png");
    tex.loadFromFile("resources/Imagenes/Mapa.png");
    menu.loadFromFile("resources/Imagenes/Menu.jpg");
    font.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");

    ManejadorPuntajes manejadorPuntajes("PuntajeG.txt");
    ManejadorClientes manejadorClientes(&manejadorPuntajes);
    Mapa map(niv, rot, &tex, &manejadorClientes);
    Chef chef(&tChef, 48, 48);
    manejadorClientes.setIngredientesPresentes(map.getIngPresentes());
    manejadorPuntajes.actualizarPosicion();

    sf::View vista(sf::Vector2f(MAPWIDTH / 2 + PANEWIDTH / 2, MAPHEIGHT / 2), sf::Vector2f(MAPWIDTH + PANEWIDTH, MAPHEIGHT));

    // # Menu inicial
    Button buttonIniciar(20, 350, 200, 75, sf::Color::Cyan);
    Button buttonSalir(20, 500, 200, 75, sf::Color::Cyan);

    textoIniciar.setString("Iniciar");
    textoIniciar.setFont(font);
    textoIniciar.setCharacterSize(40);
    textoIniciar.setOrigin(sf::Vector2f((textoIniciar.getGlobalBounds().width) / 2, (textoIniciar.getGlobalBounds().height) / 2));
    textoIniciar.setPosition(sf::Vector2f(buttonIniciar.getCenterX(), buttonIniciar.getCenterY() - 11));
    textoIniciar.setFillColor(sf::Color::Black);

    textoSalir.setString("Salir");
    textoSalir.setFont(font);
    textoSalir.setCharacterSize(40);
    textoSalir.setOrigin(sf::Vector2f((textoSalir.getGlobalBounds().width) / 2, (textoSalir.getGlobalBounds().height) / 2));
    textoSalir.setPosition(sf::Vector2f(buttonSalir.getCenterX(), buttonSalir.getCenterY() - 11));
    textoSalir.setFillColor(sf::Color::Black);

    // Fondo
    sf::Sprite imagenMenu;
    imagenMenu.setTexture(menu);
    imagenMenu.setScale(sf::Vector2f((float)SCREENWIDTH / menu.getSize().x, (float)SCREENHEIGHT / menu.getSize().y));
    imagenMenu.setPosition(0, 0);

    // Scoreboard
    txtScoreBoard.setFont(font);
    txtScoreBoard.setCharacterSize(25);
    txtScoreBoard.setFillColor(sf::Color::Black);
    txtScoreBoard.setStyle(sf::Text::Style::Bold);
    rectScoreBoard.setFillColor(sf::Color::White);
    rectScoreBoard.setOutlineColor(sf::Color::Black);
    rectScoreBoard.setOutlineThickness(10);

    auto listaPuntajes = manejadorPuntajes.listarPuntajes();
    std::string strScoreBoard = "ScoreBoard\n\n";
    for (auto &&i : listaPuntajes)
        strScoreBoard += i.getNombre() + " -> " + std::to_string(i.getPuntos()) + "\n";
    txtScoreBoard.setString(strScoreBoard);
    rectScoreBoard.setSize(sf::Vector2f(txtScoreBoard.getLocalBounds().width + 50, txtScoreBoard.getLocalBounds().height));
    rectScoreBoard.setPosition(sf::Vector2f(SCREENWIDTH - rectScoreBoard.getSize().x - 30, 90));
    txtScoreBoard.setPosition(rectScoreBoard.getPosition().x + 10, rectScoreBoard.getPosition().y);

    // # Pantalla final
    txtFin.setString("Ingrese su nombre");
    txtFin.setFont(font);
    txtFin.setCharacterSize(40);
    txtFin.setOrigin(sf::Vector2f((txtFin.getGlobalBounds().width) / 2, (txtFin.getGlobalBounds().height) / 2));
    txtFin.setPosition(sf::Vector2f(SCREENWIDTH / 2, SCREENHEIGHT / 2 - 60));
    txtFin.setFillColor(sf::Color::Black);
    txtFin.setStyle(sf::Text::Style::Italic);

    rectTxtBox.setSize(sf::Vector2f(SCREENWIDTH / 3, 40));
    rectTxtBox.setFillColor(sf::Color::White);
    rectTxtBox.setOutlineColor(sf::Color::Black);
    rectTxtBox.setOutlineThickness(3);
    rectTxtBox.setOrigin(rectTxtBox.getGlobalBounds().width / 2, rectTxtBox.getGlobalBounds().height / 2);
    rectTxtBox.setPosition(sf::Vector2f(SCREENWIDTH / 2, SCREENHEIGHT / 2));

    txtRectTxtBox.setFont(font);
    txtRectTxtBox.setCharacterSize(40);
    txtRectTxtBox.setPosition(rectTxtBox.getPosition());
    txtRectTxtBox.setFillColor(sf::Color::Black);
    txtRectTxtBox.setStyle(sf::Text::Style::Italic);

    // # Timer durante el juego
    sf::Text txtTimer;
    txtTimer.setFont(font);
    txtTimer.setFillColor(sf::Color::Black);
    txtTimer.setCharacterSize(24);
    txtTimer.setOutlineThickness(1);
    txtTimer.setScale(sf::Vector2f(0.3, 0.3));
    txtTimer.setPosition(sf::Vector2f(MAPWIDTH - 100, MAPHEIGHT - 20));

    // # Debug
    sf::Text debugText;
    sf::Font debugFont;
    if (DEBUGLEVEL == 1) {
        debugFont.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
        debugText.setFont(font);
        debugText.setCharacterSize(5);
        debugText.setFillColor(sf::Color::Red);
        debugText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered && finPartida) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                    if (strTxtBox.size() > 0)
                        strTxtBox = strTxtBox.substr(0, strTxtBox.size() - 1);
                } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && strTxtBox.size() < 20)
                    strTxtBox += static_cast<char>(event.text.unicode);
                txtRectTxtBox.setString(strTxtBox);
                txtRectTxtBox.setOrigin(sf::Vector2f((txtRectTxtBox.getGlobalBounds().width) / 2, (txtRectTxtBox.getCharacterSize()) / 2 + 10));
                // Si presiona la tecla "Enter" y por lo menos puso tres caracters como nombre cerrar
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && strTxtBox.size() > 3) {
                    manejadorPuntajes.escribirPuntaje(strTxtBox);
                    window.close();
                }
            }
            if (!jugando) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (buttonIniciar.isPressed(&window)) {
                        jugando = true;
                        timeInGame.restart();
                        map.playMusic(true);
                    } else if (buttonSalir.isPressed(&window))
                        window.close();
                }
            }
        }
        bool izq, der, arriba, abajo, interaccion, correr;
        std::string strTime;
        if (!jugando && !finPartida) {
            window.draw(imagenMenu);
            buttonIniciar.render(&window);
            buttonSalir.render(&window);
            window.draw(textoIniciar);
            window.draw(textoSalir);
            window.draw(rectScoreBoard);
            window.draw(txtScoreBoard);
        } else if (jugando) {
            window.clear(sf::Color(191, 191, 191, 0));
            if (!isVistaJuego) {
                window.setView(vista);
                isVistaJuego = true;
            }
            // Chef
            izq = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            der = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
            arriba = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
            abajo = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
            interaccion = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
            correr = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
            chef.mover(izq, der, arriba, abajo, correr);
            chef.interactuar(interaccion, &map);

            map.dibujar(&window);
            chef.dibujar(&window, &map);
            manejadorClientes.dibujar(&window);
            manejadorPuntajes.dibujar(&window);
            int tiempoActual = timeInGame.getElapsedTime().asSeconds();
            if (tiempoActual / 60 > 0)
                strTime = std::to_string(tiempoActual / 60) + " : " + std::to_string(tiempoActual % 60);
            else
                strTime = std::to_string(tiempoActual % 60);
            txtTimer.setString(strTime);
            if (tiempoActual < tiempoDeJuego / 3)
                txtTimer.setFillColor(sf::Color::Green);
            else if (tiempoActual < (tiempoDeJuego * 2) / 3)
                txtTimer.setFillColor(sf::Color::Yellow);
            else
                txtTimer.setFillColor(sf::Color::Red);
            if (tiempoActual > tiempoDeJuego) {
                jugando = false;
                finPartida = true;
            }
            window.draw(txtTimer);
        } else if (finPartida) {
            window.clear(sf::Color(84, 153, 199, 0));
            if (isVistaJuego) {
                isVistaJuego = false;
                window.setView(window.getDefaultView());
            }
            window.draw(txtFin);
            window.draw(rectTxtBox);
            window.draw(txtRectTxtBox);
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