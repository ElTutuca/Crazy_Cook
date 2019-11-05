#ifndef LISTA_INGREDIENTES_H
#define LISTA_INGREDIENTES_H
#include "Ingrediente.h"
#include "Plato.h"
#include <list>

class ListaIngredientes {
private:
    // Cada ingrediente
    std::list<Ingrediente> listaIng;
    // Tick o no tick
    std::list<bool> listaEstados;

public:
    ListaIngredientes();
    ListaIngredientes(std::list<Ingrediente> listaIng);
    ListaIngredientes(Plato p);
    ~ListaIngredientes();
    void tickIngrediente(Ingrediente ing);
    void untickIngrediente(Ingrediente ing);
};

#endif
