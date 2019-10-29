#include "../includes/Ingrediente.h"
#include "../includes/Chef.h"
#include "../includes/Definiciones.h"

Ingrediente::Ingrediente() {
}
Ingrediente::~Ingrediente() {
}
Ingrediente::Ingrediente(sf::Vector2f pos, float ang, sf::Texture *tex, IngredienteType tipo) : Agarrable(pos, ang, tex, true) {
    this->tipo = tipo;
}

IngredienteType Ingrediente::getIngredienteType() {
    return tipo;
}