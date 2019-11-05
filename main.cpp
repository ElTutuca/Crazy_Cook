#include "includes/Button.h"
#include "includes/Chef.h"
#include "includes/Definiciones.h"
#include "includes/Espacio.h"
#include "includes/ListaIngredientes.h"
#include "includes/ManejadorRecetas.h"
#include "includes/Mapa.h"
#include "includes/Suelo.h"
#include "includes/Cliente.h"
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

    bool jugar = false;

    sf::Font font;
    font.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
    SCREENWIDTH = sf::VideoMode::getDesktopMode().width;
    SCREENHEIGHT = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode(1300, 750), "SFML works!");
    // Vector de vectores
    // niv es el tipo de tiles ordenado en columnas
    std::vector<std::vector<int>> niv = {{1, 3, 3, 1, 1, 1}, {1, 0, 0, 0, 0, 1}, {4, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 1}, {5, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 6, 6, 1, 1}};
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

    sf::Texture tex, tChef, menu, tC1, tC2, tC3;
    tChef.loadFromFile("resources/Imagenes/Chef.png");
    tex.loadFromFile("resources/Imagenes/Mapa.png");
    menu.loadFromFile("resources/Imagenes/Menu.jpg");
	tC1.loadFromFile("resources/Imagenes/Cliente_1.png");
	tC2.loadFromFile("resources/Imagenes/Cliente_2.png");
	tC3.loadFromFile("resources/Imagenes/Cliente_3.png");
    MENUWIDTH = menu.getSize().x;
    MENUHEIGHT = menu.getSize().y;

    // ManejadorRecetas manejadorRecetas("Texto/RecetasG.txt");
    // Plato p = manejadorRecetas.getPlato(0);
    // ListaIngredientes listaIngredientes(p);
    // std::list<std::string> listaStr = listaIngredientes.getStrings();
    // listaIngredientes.tickIngrediente(p.top());
    // listaStr = listaIngredientes.getStrings();

    sf::Sprite imagenMenu;
    imagenMenu.setTexture(menu);

    //Se crea el mapa y se mandan tipo de tiles y su rotacion, con  la textura del mapa
    Mapa map(niv, rot, &tex);
    Chef chef(&tChef, 48, 48);

	//Cliente c1(/*posicion*/,tC1,/*Plato*/,/*Tiempo de Espera=NdeIngDelPlato*15 */);
	//Cliente c2(/*posicion*/,tC2,/*Plato*/,/*Tiempo de Espera=NdeIngDelPlato*15 */);
	//Cliente c3(/*posicion*/,tC3,/*Plato*/,/*Tiempo de Espera=NdeIngDelPlato*15 */);
	Cliente c1(sf::Vector2f(MAPWIDTH,0),&tC1,0);
	Cliente c2(sf::Vector2f(MAPWIDTH,(MAPHEIGHT/6)*2),&tC2,(MAPHEIGHT/6)*2);
	Cliente c3(sf::Vector2f(MAPWIDTH,(MAPHEIGHT/6)*4),&tC3,(MAPHEIGHT/6)*4);
	
	std::cout<<SCREENHEIGHT/6<<std::endl;
	
    sf::View vista(sf::Vector2f(MAPWIDTH / 2 + PANEWIDTH / 2, MAPHEIGHT / 2), sf::Vector2f(MAPWIDTH + PANEWIDTH, MAPHEIGHT));

    sf::Text debugText;
    sf::Font debugFont;
    if (DEBUGLEVEL == 1) {
        debugFont.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
        debugText.setFont(font);
        debugText.setCharacterSize(24);
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
        window.clear(sf::Color(191,191,191,0));
        if (!jugar) {
            window.draw(imagenMenu);
            buttonIniciar.render(&window);
            buttonSalir.render(&window);
            window.draw(textoIniciar);
            window.draw(textoSalir);
        }

        bool izq, der, arriba, abajo, interaccion, correr;
        if (jugar) {
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
			c1.mostrar(&window);
			c2.mostrar(&window);
			c3.mostrar(&window);
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
