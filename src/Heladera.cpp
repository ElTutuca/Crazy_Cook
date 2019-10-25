#include "../includes/Heladera.h"


Heladera::Heladera(sf::Vector2i pos, int rot, sf::Vector2i size,IngredienteType ingrediente) : Espacio(pos, rot) {
    dibujable = false;
    setTipo(TileType::Heladera);
    setSizeTile(size);




}