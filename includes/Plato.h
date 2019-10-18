#ifndef PLATO_H
#define PLATO_H
#include "Ingrediente.h"
#include <stack>

class Plato {
private:
    std::stack<Ingrediente> plato;

public:
    void addIngrediente(Ingrediente ing);
    Ingrediente popIngrediente();
    void dibujar(sf::RenderWindow *w);
};

#endif //PLATO_H
