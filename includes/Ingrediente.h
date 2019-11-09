#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include "Agarrable.h"
#include "Definiciones.h"
#include "Espacio.h"
#include <SFML/Graphics.hpp>

// Extiende de agarrable
class Ingrediente : public Agarrable {
private:
    IngredienteType tipo;

public:
    Ingrediente();
    Ingrediente(IngredienteType tipo);
    ~Ingrediente();
    Ingrediente(sf::Vector2f pos, float ang, sf::Texture *tex, IngredienteType tipo);
    IngredienteType getIngredienteType();
    void setIngredienteType(IngredienteType cambio);
    bool operator==(const Ingrediente ing1);
};

#endif // INGREDIENTE_H
