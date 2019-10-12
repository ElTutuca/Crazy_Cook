#include "../includes/Suelo.h"
#include <iostream>

Suelo::Suelo(sf::Vector2i pos, int rot, sf::Texture *tex) : Espacio(pos, rot) {
    spt.setTexture(*tex);

    float texturaAncho = spt.getTexture()->getSize().x;
    float texturaAlto = spt.getTexture()->getSize().y;

    float anchoTile = texturaAncho * spt.getScale().x;
    float altoTile = texturaAlto * spt.getScale().y;

    spt.setOrigin(texturaAncho / 2, texturaAlto / 2);

    float posX = getPosicion().x * anchoTile + anchoTile / 2 + offsetX;
    float posY = getPosicion().y * altoTile + altoTile / 2 + offsetY;

    spt.setPosition(posX, posY);

    spt.setRotation(rotacion * 90);
}

void Suelo::dibujar(sf::RenderWindow *w) {
    // std::cout << getPosicion().x << " - " << getPosicion().y << std::endl;
    w->draw(spt);
}
