#include "../includes/Cliente.h"
#include "../includes/Definiciones.h"
#include "../includes/ListaIngredientes.h"
#include "../includes/Plato.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>

Cliente::Cliente(sf::Vector2f pos, sf::Texture *tCliente, Plato pedido, int tiempo) {
    sCliente.setTexture(*tCliente);
    sCliente.setPosition(pos);

    //listaIng.ListaIngredientes(pedido);

    orden = pedido;

    dtTranscurrido.restart();

    tiempoEspera = tiempo;

    sf::Font font;
    font.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
    this->humor.setString("Feliz");
    this->humor.setFont(font);
    this->humor.setCharacterSize(30);
    this->humor.setOrigin(sf::Vector2f(0, (humor.getGlobalBounds().height) / 2));
    //this->humor.setPosition(sf::Vector2f(,));
    this->humor.setFillColor(sf::Color::Green);

    this->shape.setPosition(sf::Vector2f(MAPWIDTH, MAPHEIGHT / 6));
    this->shape.setSize(sf::Vector2f(PANEWIDTH, MAPHEIGHT / 6));
    this->shape.setFillColor(sf::Color::Yellow);
    this->shape.setOutlineColor(sf::Color::Black);
}

// Seguro este es el que vamos a terminar usando
Cliente::Cliente(sf::Texture *tCliente, Plato pedido, int tiempoEspera) {
    sCliente.setTexture(*tCliente);
    sCliente.setPosition(MAPWIDTH, 0);

    posShape = sf::Vector2f(MAPWIDTH, MAPHEIGHT / 6);
    shape.setPosition(posShape);
    shape.setSize(sf::Vector2f(PANEWIDTH, MAPHEIGHT / 6));
    shape.setFillColor(sf::Color::Yellow);
    shape.setOutlineColor(sf::Color::Black);

    posHumor = sf::Vector2f(sCliente.getPosition().x + sCliente.getTexture()->getSize().x / 2 + 10, sCliente.getTexture()->getSize().y / 2);
    fontHumor.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
    humor.setFont(fontHumor);
    humor.setString("Feliz");
    humor.setFillColor(sf::Color::Green);
    humor.setScale(sf::Vector2f(0.35, 0.35));
    humor.setCharacterSize(24);
    humor.setOutlineThickness(1);
    humor.setOrigin(sf::Vector2f(0, (humor.getGlobalBounds().height) / 2));
    humor.setPosition(posHumor);

    listaIng.setPlato(pedido);
    orden = pedido;

    posLista = sf::Vector2f(shape.getPosition().x + 4, shape.getPosition().y + 2);
    txtIngredientes.setFont(fontHumor);
    actualizarIngredientes();
    txtIngredientes.setFillColor(sf::Color::Black);
    txtIngredientes.setScale(sf::Vector2f(0.16, 0.16));
    txtIngredientes.setCharacterSize(24);
    txtIngredientes.setOutlineThickness(0.2);
    txtIngredientes.setPosition(posLista);

    this->tiempoEspera = tiempoEspera;
    dtTranscurrido.restart();
}

/**
@deprecated 
*/
Cliente::Cliente(sf::Vector2f pos, sf::Texture *tCliente) {
    sCliente.setTexture(*tCliente);
    sCliente.setPosition(pos);

    shape.setPosition(sf::Vector2f(MAPWIDTH, MAPHEIGHT / 6));
    shape.setSize(sf::Vector2f(PANEWIDTH, MAPHEIGHT / 6));
    shape.setFillColor(sf::Color::Yellow);
    shape.setOutlineColor(sf::Color::Black);
}

Cliente::~Cliente() {
}
ListaIngredientes *Cliente::getListaIngredientes() {
    return &listaIng;
}

void Cliente::actualizarIngredientes() {
    std::list<std::string> listaIngred = listaIng.getStrings();
    std::list<std::string>::iterator itIngrediente;
    strIngredientes = "";
    for (itIngrediente = listaIngred.begin(); itIngrediente != listaIngred.end(); itIngrediente++) {
        strIngredientes += "* " + *itIngrediente + "\n";
    }
    txtIngredientes.setString(strIngredientes);
}

void Cliente::setOffset(sf::Vector2f v2) {
    offset = v2;
    sCliente.setPosition(sCliente.getPosition().x + v2.x, v2.y);
    shape.setPosition(posShape.x + offset.x, posShape.y + offset.y);
    humor.setPosition(posHumor.x + offset.x, posHumor.y + offset.y);
    txtIngredientes.setPosition(posLista.x + offset.x, posLista.y + offset.y);
}
void Cliente::setOffset(float x, float y) {
    setOffset(sf::Vector2f(x, y));
}
sf::Vector2i Cliente::getSize() {
    return sf::Vector2i(shape.getSize().x, shape.getSize().y * 2);
}

/*0: Feliz - 1: Contento - 2: Normal - 3: Descontento - 4: Enojado*/
void Cliente::actualizarHumor() {
    if (dtTranscurrido.getElapsedTime().asSeconds() < this->tiempoEspera / 4) {
        this->humor.setString("Feliz");
    } else if (dtTranscurrido.getElapsedTime().asSeconds() > this->tiempoEspera / 4 && dtTranscurrido.getElapsedTime().asSeconds() < this->tiempoEspera / 2) {
        this->humor.setString("Content@");
    } else if (dtTranscurrido.getElapsedTime().asSeconds() > this->tiempoEspera / 2 &&
               dtTranscurrido.getElapsedTime().asSeconds() < this->tiempoEspera * (3 / 4)) {
        this->humor.setString("Neutral");
        this->humor.setFillColor(sf::Color::Cyan);
    } else if (dtTranscurrido.getElapsedTime().asSeconds() > this->tiempoEspera * (3 / 4) && dtTranscurrido.getElapsedTime().asSeconds() < this->tiempoEspera) {
        this->humor.setString("Descontent@");
        this->humor.setFillColor(sf::Color::Yellow);
    } else if (dtTranscurrido.getElapsedTime().asSeconds() > this->tiempoEspera) {
        this->humor.setString("Enojad@");
        this->humor.setFillColor(sf::Color::Red);
    }
}

void Cliente::mostrar(sf::RenderWindow *w) {
    actualizarHumor();
    actualizarIngredientes();
    humor.setFont(fontHumor);
    txtIngredientes.setFont(fontHumor);
    w->draw(sCliente);
    w->draw(shape);
    w->draw(humor);
    w->draw(txtIngredientes);
}

bool Cliente::recibioPedido(Plato *entregado) {
    return orden == *entregado;
}
