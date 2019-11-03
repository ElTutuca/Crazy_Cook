#ifndef PLATO_H
#define PLATO_H
// #include "../includes/Agarrable.h"
#include "Ingrediente.h"
#include "Nodo.h"

class Plato : public Agarrable {
private:
    Nodo<Ingrediente> *cima;
    unsigned int tamanio;
    void dibujarIngredientes(sf::RenderWindow *w);

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
    void setPosicion(sf::Vector2f pos) override;
    void dibujar(sf::RenderWindow *w) override;
    void agarrado(float x, float y, float angulo, float anchoChef) override;
};

#endif //PLATO_H
