#include "../includes/Plato.h"
#include "../includes/Ingrediente.h"
#include <math.h>

Plato::Plato() {
    tamanio = 0;
}
Plato::Plato(sf::Vector2f pos, float ang, sf::Texture *tex) : Agarrable(pos, ang, tex, false) {
    tamanio = 0;
}

Plato::~Plato() {
    while (!pilaIngredientes.empty())
        popIngrediente();
}

void Plato::pushIngrediente(Ingrediente ing) {
    pilaIngredientes.push(ing);
}

Ingrediente Plato::popIngrediente() {
    Ingrediente r = pilaIngredientes.top();
    pilaIngredientes.pop();
    return r;
}

void Plato::dibujar(sf::RenderWindow *w) {
    spt.setPosition(posicion);
    spt.setRotation(angulo);
    w->draw(spt);
    dibujarIngredientes(w);
}
void Plato::dibujarIngredientes(sf::RenderWindow *w) {
    if (!empty()) {
        Ingrediente aux = top();
        popIngrediente();
        dibujarIngredientes(w);
        aux.dibujar(w);
        pushIngrediente(aux);
    }
}
void Plato::agarrado(float x, float y, float angulo, float anchoChef) {
    this->angulo = angulo;
    posicion.x = x + anchoChef * sin(degToRad(angulo));
    posicion.y = y - anchoChef * cos(degToRad(angulo));
    for (int i = 0; i < size(); i++) {
        // aux->dato.agarrado(x, y, angulo, anchoChef);
        // aux = aux->next;
    }
}
void Plato::setPosicion(sf::Vector2f pos) {
    // posicion = pos;
    // Nodo<Ingrediente> *aux = cima;
    // for (int i = 0; i < size(); i++) {
    //     aux->dato.setPosicion(pos);
    //     aux = aux->next;
    // }
}
Ingrediente Plato::top() {
    // if (cima == nullptr)
    //     throw 404;
    Ingrediente ing;
    return ing;
}

bool Plato::empty() {
    return pilaIngredientes.empty();
}

int Plato::size() {
    return tamanio;
}
bool Plato::operator==(Plato p2) {
    bool r = size() == p2.size();
    if (!r)
        return r;

    // Nodo<Ingrediente> *aux1 = cima;
    // Nodo<Ingrediente> *aux2 = p2.cima;
    // for (int i = 0; i < size() && r; i++) {
    //     r = r && aux1->dato.getIngredienteType() == aux2->dato.getIngredienteType();
    //     aux1 = aux1->next;
    //     aux2 = aux2->next;
    // }
    return r;
}