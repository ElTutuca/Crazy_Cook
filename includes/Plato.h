#ifndef PLATO_H
#define PLATO_H
// #include "../includes/Agarrable.h"
#include "Ingrediente.h"
#include <stack>

class Plato : public Agarrable {
private:
    std::stack<Ingrediente> pilaIngredientes;
    void dibujarIngredientes(sf::RenderWindow *w);
    void acutalizarPosIngredientes(float x, float y, float angulo, float anchoChef, Ingrediente ing);
    void acutalizarPosIngredientes(Ingrediente ing);

public:
    Plato();
    Plato(sf::Vector2f pos, float ang, sf::Texture *tex);
    ~Plato();
    void pushIngrediente(Ingrediente ing);
    Ingrediente popIngrediente();
    bool empty();
    int size();
    Ingrediente top();
    bool operator==(Plato p2);
    bool operator!=(Plato p2);
    void setPosicion(sf::Vector2f pos) override;
    void dibujar(sf::RenderWindow *w) override;
    void agarrado(float x, float y, float angulo, float anchoChef) override;
};

#endif //PLATO_H
