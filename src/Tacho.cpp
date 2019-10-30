#include "Tacho.h"
#include "../includes/Definiciones.h"

Tacho::Tacho(sf::Vector2i pos, int rot, sf::Vector2f size) {

    dibujable = false;
    setTipo(TileType::Tacho);
    setSizeTile(size);
    rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2 + offsetX, getPosicion().y * getSizeTile().y + getSizeTile().y / 2 + offsetY);
    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::Magenta);
        rectShape.setOutlineThickness(1);
        rectShape.setFillColor(sf::Color::Transparent);
    }
}
void Tacho::dibujar(sf::RenderWindow *w) {
    if (dibujable || DEBUGLEVEL == 1) {
        w->draw(rectShape);
    }

}
bool Tacho :: Tirar(Agarrable *ag){
    if(ag != nullptr ) {
        delete ag;
        return true;
    }
    else{
        return false;
    }


}