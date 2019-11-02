#ifndef HELADERA_H
#define HELADERA_H
#include "Chef.h"
#include "Espacio.h"
#include "Ingrediente.h"

class Heladera : public Espacio {
private:
  Ingrediente *ingrediente;

public:
  Heladera(sf::Vector2i pos, int rot, sf::Vector2f size, Ingrediente *ingred);
  ~Heladera();
  Ingrediente *getIngrediente();
  void dibujar(sf::RenderWindow *w) override;
};
#endif // HELADERA_H
