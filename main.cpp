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
int MENUWIDTH = 0;
int MENUHEIGHT = 0;
int MAPWIDTH = 0;
int MAPHEIGHT = 0;
int PANEWIDTH = 60;
const int TILEWIDTH = 32;
const int TILEHEIGHT = 32;
int main() {

    bool jugar = false, fin = false;
    sf::Clock timeInGame;
    int tiempoDeJuego = 120;

    sf::Font font;
    font.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
    SCREENWIDTH = sf::VideoMode::getDesktopMode().width;
    SCREENHEIGHT = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Crazy Cook");
    // niv es el tipo de tiles ordenado en columnas
    std::vector<std::vector<int>> niv = {{1, 3, 3, 3, 3, 1}, {3, 0, 0, 0, 0, 1}, {4, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 1}, {5, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 6, 6, 1, 1}};
    // rot es la rotacion de cada tile
    std::vector<std::vector<int>> rot = {{0, 3, 3, 3, 3, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

    Button buttonIniciar(20, 350, 200, 75, sf::Color::Cyan);
    Button buttonSalir(20, 500, 200, 75, sf::Color::Cyan);

    sf::Texture tex, tChef, menu;
    tChef.loadFromFile("resources/Imagenes/Chef.png");
    tex.loadFromFile("resources/Imagenes/Mapa.png");
    menu.loadFromFile("resources/Imagenes/Menu.jpg");
    MENUWIDTH = menu.getSize().x;
    MENUHEIGHT = menu.getSize().y;

    sf::Text textoIniciar;
    textoIniciar.setString("Iniciar");
    textoIniciar.setFont(font);
    textoIniciar.setCharacterSize(40);
    textoIniciar.setOrigin(sf::Vector2f((textoIniciar.getGlobalBounds().width) / 2, (textoIniciar.getGlobalBounds().height) / 2));
    textoIniciar.setPosition(sf::Vector2f(buttonIniciar.getCenterX(), buttonIniciar.getCenterY() - 11));
    textoIniciar.setFillColor(sf::Color::Black);

    sf::Text textoSalir;
    textoSalir.setString("Salir");
    textoSalir.setFont(font);
    textoSalir.setCharacterSize(40);
    textoSalir.setOrigin(sf::Vector2f((textoSalir.getGlobalBounds().width) / 2, (textoSalir.getGlobalBounds().height) / 2));
    textoSalir.setPosition(sf::Vector2f(buttonSalir.getCenterX(), buttonSalir.getCenterY() - 11));
    textoSalir.setFillColor(sf::Color::Black);

    // # Pantalla final
    std::string strTxtBox = "";
    sf::Text txtFin;
    txtFin.setString("Ingrese su nombre");
    txtFin.setFont(font);
    txtFin.setCharacterSize(40);
    txtFin.setOrigin(sf::Vector2f((txtFin.getGlobalBounds().width) / 2, (txtFin.getGlobalBounds().height) / 2));
    txtFin.setPosition(sf::Vector2f(SCREENWIDTH / 2, SCREENHEIGHT / 2 - 60));
    txtFin.setFillColor(sf::Color::Black);
    txtFin.setStyle(sf::Text::Style::Italic);

    sf::RectangleShape rectTxtBox;
    rectTxtBox.setSize(sf::Vector2f(SCREENWIDTH / 3, 40));
    rectTxtBox.setFillColor(sf::Color::White);
    rectTxtBox.setOutlineColor(sf::Color::Black);
    rectTxtBox.setOutlineThickness(3);
    rectTxtBox.setOrigin(rectTxtBox.getGlobalBounds().width / 2, rectTxtBox.getGlobalBounds().height / 2);
    rectTxtBox.setPosition(sf::Vector2f(SCREENWIDTH / 2, SCREENHEIGHT / 2));

    sf::Text txtRectTxtBox;
    txtRectTxtBox.setFont(font);
    txtRectTxtBox.setCharacterSize(40);
    txtRectTxtBox.setPosition(rectTxtBox.getPosition());
    txtRectTxtBox.setFillColor(sf::Color::Black);
    txtRectTxtBox.setStyle(sf::Text::Style::Italic);

    sf::RectangleShape rectScoreBoard;
    sf::Text txtScoreBoard;
    txtScoreBoard.setFont(font);
    txtScoreBoard.setCharacterSize(25);
    txtScoreBoard.setOrigin(sf::Vector2f((textoIniciar.getGlobalBounds().width) / 2, (textoIniciar.getGlobalBounds().height) / 2));
    txtScoreBoard.setPosition(sf::Vector2f(MENUWIDTH + 80, 40));
    txtScoreBoard.setFillColor(sf::Color::Black);
    rectScoreBoard.setFillColor(sf::Color::White);
    rectScoreBoard.setOutlineColor(sf::Color::Black);
    rectScoreBoard.setOutlineThickness(10);
    rectScoreBoard.setOrigin(rectScoreBoard.getGlobalBounds().width / 2, rectScoreBoard.getGlobalBounds().height / 2);
    rectScoreBoard.setPosition(sf::Vector2f(MENUWIDTH, 25));

    sf::Sprite imagenMenu;
    imagenMenu.setTexture(menu);

    //Se crea el mapa y se mandan tipo de tiles y su rotacion, con  la textura del mapa
    ManejadorPuntajes manejadorPuntajes("PuntajeG.txt");
    ManejadorClientes manejadorClientes(&manejadorPuntajes);
    Mapa map(niv, rot, &tex, &manejadorClientes);
    manejadorClientes.setIngredientesPresentes(map.getIngPresentes());
    Chef chef(&tChef, 48, 48);
    manejadorPuntajes.actualizarPosicion();

    auto listaPuntajes = manejadorPuntajes.listarPuntajes();
    std::string strScoreBoard = "ScoreBoard\n";
    for (auto &&i : listaPuntajes) {
        strScoreBoard += i.getNombre() + " -> " + std::to_string(i.getPuntos()) + "\n";
    }
    txtScoreBoard.setString(strScoreBoard);
    rectScoreBoard.setSize(sf::Vector2f(txtScoreBoard.getLocalBounds().width + 50, txtScoreBoard.getLocalBounds().height));

    sf::Text txtTimer;
    txtTimer.setFont(font);
    txtTimer.setFillColor(sf::Color::Black);
    txtTimer.setCharacterSize(24);
    txtTimer.setOutlineThickness(1);
    txtTimer.setScale(sf::Vector2f(0.3, 0.3));
    txtTimer.setPosition(sf::Vector2f(MAPWIDTH - 100, MAPHEIGHT - 20));

    sf::View vista(sf::Vector2f(MAPWIDTH / 2 + PANEWIDTH / 2, MAPHEIGHT / 2), sf::Vector2f(MAPWIDTH + PANEWIDTH, MAPHEIGHT));

    sf::Text debugText;
    sf::Font debugFont;
    if (DEBUGLEVEL == 1) {
        debugFont.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
        debugText.setFont(font);
        debugText.setCharacterSize(5);
        debugText.setFillColor(sf::Color::Red);
        debugText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }

    window.setFramerateLimit(60);
    bool isVistaJuego = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered && fin) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                    if (strTxtBox.size() > 0)
                        strTxtBox = strTxtBox.substr(0, strTxtBox.size() - 1);
                } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && strTxtBox.size() < 20) {
                    strTxtBox += static_cast<char>(event.text.unicode);
                }
                txtRectTxtBox.setString(strTxtBox);
                txtRectTxtBox.setOrigin(sf::Vector2f((txtRectTxtBox.getGlobalBounds().width) / 2, (txtRectTxtBox.getCharacterSize()) / 2 + 10));
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && strTxtBox.size() > 3) {
                    manejadorPuntajes.escribirPuntaje(strTxtBox);
                    window.close();
                }
            }
            if (!jugar) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (buttonIniciar.isPressed(&window)) {
                        jugar = true;
                        timeInGame.restart();
                    }
                    if (buttonSalir.isPressed(&window))
                        window.close();
                }
            }
        }
        window.clear(sf::Color(191, 191, 191, 0));
        bool izq, der, arriba, abajo, interaccion, correr;
        std::string strTime;
        if (!jugar && !fin) {
            window.draw(imagenMenu);
            buttonIniciar.render(&window);
            buttonSalir.render(&window);
            window.draw(textoIniciar);
            window.draw(textoSalir);
            window.draw(rectScoreBoard);
            window.draw(txtScoreBoard);
        } else if (jugar) {
            if (!isVistaJuego) {
                window.setView(vista);
                isVistaJuego = true;
            }
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
                jugar = false;
                fin = true;
            }
            window.draw(txtTimer);
        } else if (fin) {
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
