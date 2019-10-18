#include "../includes/Plato.h"
#include "../includes/Ingrediente.h"

void Plato::addIngrediente(Ingrediente ing) {
    plato.push(ing);
}
Ingrediente Plato::popIngrediente() {
    Ingrediente ing = plato.top();
    plato.pop();
    return ing;
}
void Plato::dibujar(sf::RenderWindow *w) {

    // while (plato.) {
    // }
}