#include "../includes/Plato.h"
#include "../includes/Ingrediente.h"
#include <math.h>

Plato::Plato() {
}
Plato::Plato(sf::Vector2f pos, float ang, sf::Texture *tex) : Agarrable(pos, ang, tex, false) {
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
    if (!pilaIngredientes.empty())
        acutalizarPosIngredientes(x, y, angulo, anchoChef, pilaIngredientes.top());
}
void Plato::acutalizarPosIngredientes(float x, float y, float angulo, float anchoChef, Ingrediente ing) {
    ing.agarrado(x, y, angulo, anchoChef);
    popIngrediente();
    if (!empty())
        acutalizarPosIngredientes(x, y, angulo, anchoChef, top());
    pushIngrediente(ing);
}
void Plato::acutalizarPosIngredientes(Ingrediente ing) {
    ing.setPosicion(posicion);
    popIngrediente();
    if (!empty())
        acutalizarPosIngredientes(top());
    pushIngrediente(ing);
}
void Plato::setPosicion(sf::Vector2f pos) {
    posicion = pos;
    if (!empty())
        acutalizarPosIngredientes(top());
}
Ingrediente Plato::top() {
    if (empty())
        throw 404;
    return pilaIngredientes.top();
}

bool Plato::empty() {
    return pilaIngredientes.empty();
}

int Plato::size() {
    return pilaIngredientes.size();
}
bool Plato::operator==(Plato p2) {
    bool r = size() == p2.size();
    if (!r)
        return r;
    std::stack<Ingrediente> pila1 = pilaIngredientes;
    std::stack<Ingrediente> pila2 = p2.pilaIngredientes;
    for (int i = 0; i < size() && r; i++) {
        r = r && pila1.top() == pila2.top();
        pila1.pop();
        pila2.pop();
    }
    return r;
}
bool Plato::operator!=(Plato p2) {
    return !(*this == p2);
}