#ifndef LISTA_INGREDIENTES_H
#define LISTA_INGREDIENTES_H
#include "Ingrediente.h"
#include "Plato.h"
#include <list>
#include <string>

class ListaIngredientes {
private:
    // Cada ingrediente
    std::list<Ingrediente> listaIngr;
    // Tick o no tick
    std::list<bool> listaEstados;
    void cambiarEstado(Ingrediente ing, bool estado);

public:
    ListaIngredientes();
    ListaIngredientes(std::list<Ingrediente> listaIng);
    ListaIngredientes(Plato p);
    ~ListaIngredientes();
    std::list<std::string> getStrings();
    void tickIngrediente(Ingrediente ing);
    void untickIngrediente(Ingrediente ing);
};

#endif
