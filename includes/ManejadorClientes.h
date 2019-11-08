#ifndef MANEJADOR_CLIENTES_H
#define MANEJADOR_CLIENTES_H
#include "../includes/ManejadorRecetas.h"
#include "Cliente.h"
#include <queue>
class ManejadorClientes {
private:
    std::queue<Cliente> colaClientes;
    sf::Texture tClientes[3];
    sf::Clock dt;
    int esperaProxCliente;
    ManejadorRecetas manRecetas;
    Mapa *map;
    void pushCliente(Cliente ing);
    Cliente popCliente();
    bool empty();
    int size();
    Cliente front();
    // Tiene toda la logica
    void correr();

public:
    ManejadorClientes();
    ManejadorClientes(Mapa *map);
    void setMapa(Mapa *map);
    ~ManejadorClientes();
    void dibujar(sf::RenderWindow *w);
};

#endif