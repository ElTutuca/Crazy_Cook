#ifndef MANEJADOR_CLIENTES_H
#define MANEJADOR_CLIENTES_H
#include "Cliente.h"
#include "ManejadorPuntajes.h"
#include "ManejadorRecetas.h"
#include <queue>
class ManejadorClientes {
private:
    std::queue<Cliente> colaClientes;
    sf::Texture tClientes[3];
    sf::Clock dt;
    int esperaProxCliente;
    ManejadorRecetas manRecetas;
    ManejadorPuntajes *manPuntajes;
    std::list<IngredienteType> *ingPresentes;
    void pushCliente(Cliente cli);
    void pushCliente(Cliente cli, int pos);
    bool empty();
    int size();
    Cliente front();
    // Tiene toda la logica
    void correr();

public:
    ManejadorClientes();
    ManejadorClientes(ManejadorPuntajes *manPunt);
    ManejadorClientes(std::list<IngredienteType> *ingPres);
    void setIngredientesPresentes(std::list<IngredienteType> *ingPres);
    void sendPlato(Plato *p);
    ~ManejadorClientes();
    void dibujar(sf::RenderWindow *w);
};

#endif