#ifndef CLIENTE_H
#define CLIENTE_H

#include "../includes/ListaIngredientes.h"
#include "../includes/Plato.h"
#include <SFML/Graphics.hpp>

class Cliente {
private:
    sf::Clock dtTranscurrido;
    /*variable, depende del pedido*/
    int tiempoEspera;
    sf::Vector2f offset;
    Plato orden;
    sf::Sprite sCliente;
    sf::Text humor;
    sf::Text txtIngredientes;
    std::string strIngredientes;
    sf::Font fontHumor;
    ListaIngredientes listaIng;
    sf::RectangleShape shape;

    void actualizarIngredientes();

public:
    Cliente(sf::Vector2f pos, sf::Texture *tCliente, Plato pedido, int tiempoEspera);
    Cliente(sf::Texture *tCliente, Plato pedido, int tiempoEspera);
    Cliente(sf::Vector2f pos, sf::Texture *tCliente);
    ~Cliente();
    void actualizarHumor();

    ListaIngredientes *getListaIngredientes();
    void setOffset(sf::Vector2f v2);
    void setOffset(float x, float y);
    sf::Vector2i getSize();
    void mostrar(sf::RenderWindow *w);
    bool recibioPedido(Plato *entregado);
};

#endif
