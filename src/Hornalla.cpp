#include "../includes/Hornalla.h"

Hornalla::Hornalla(sf::Vector2i pos, int rot, sf::Vector2f size, Mapa *map) : Espacio(pos, rot) {
    this->map = map;
    dibujable = false;
    setTipo(TileType::Hornalla);
    setSizeTile(size);
    rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2 + offsetX, getPosicion().y * getSizeTile().y + getSizeTile().y / 2 + offsetY);
    item = nullptr;
    texPrendida.loadFromFile("resources/Imagenes/Hornalla_Prendida.png");
    rectShape.setTexture(&texPrendida);
    hacerCoccion = true;
    if (!sonido.loadFromFile("resources/Sound/Sonido_Hornalla.wav"))
        std::cout << "No anduvo sonido" << std::endl;
    sonidoCocinando.setBuffer(sonido);
    sonidoCocinando.setVolume(10);

    if (DEBUGLEVEL == 1) {
        rectShape.setOutlineColor(sf::Color::White);
        rectShape.setOutlineThickness(0.7);
        rectShape.setFillColor(sf::Color::Transparent);
    }
}
Hornalla::~Hornalla() {
    hacerCoccion = true;
}
void Hornalla::coccion() {
    sf::Texture *tex = new sf::Texture();
    tex->loadFromFile("resources/Imagenes/Hamburguesa_Cocinada.png");
    item->setTexture(tex);
    map->actualizarIngPresentes(IngredienteType::HamburgesaCruda, false);
    Ingrediente *nuevIng = (Ingrediente *)item;
    nuevIng->setIngredienteType(IngredienteType::HamburgesaCocinada);
    map->actualizarIngPresentes(IngredienteType::HamburgesaCocinada, true);
    hacerCoccion = false;
}

bool Hornalla::cocinar(Ingrediente *ing) {
    if (ing->getIngredienteType() == IngredienteType::HamburgesaCruda) {
        if (item == nullptr) {
            item = ing;
            item->setPosicion(sf::Vector2f(getPosicion().x * getSizeTile().x + getSizeTile().x / 2, getPosicion().y * getSizeTile().y + getSizeTile().y / 2));
            dibujable = true;
            sonidoCocinando.play();
            return true;
        }
        return false;
    }
    return false;
}
Agarrable *Hornalla::popCocinado() {
    Agarrable *r = item;
    if (item != nullptr) {
        item = nullptr;
        hacerCoccion = true;
    }
    dibujable = false;
    return r;
}
void Hornalla::dibujar(sf::RenderWindow *w) {
    if (dibujable || DEBUGLEVEL == 1) {
        w->draw(rectShape);
    }
    if (item != nullptr) {
        item->dibujar(w);
        if (dtCocinar.getElapsedTime().asMilliseconds() > tiempoCoccion && hacerCoccion)
            coccion();
    } else

        dtCocinar.restart();
}
