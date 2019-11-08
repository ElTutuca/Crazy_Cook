#ifndef HORNALLA_H
#define HORNALLA_H
#include "../includes/Definiciones.h"
#include "../includes/Ingrediente.h"
#include "Espacio.h"
class Hornalla : public Espacio {
private:
    Mapa *map;
    bool hacerCoccion;

public:
    Hornalla(sf::Vector2i pos, int rot, sf::Vector2f size, Mapa *map);
    ~Hornalla();
    sf::Texture texPrendida;
	sf::Sound sonidoCocinando;
	sf::SoundBuffer sonido;
    void coccion();
    bool cocinar(Ingrediente *ing);
    Agarrable *popCocinado();
    Agarrable *getAgarrable();
    void dibujar(sf::RenderWindow *w) override;
    sf::Clock dtCocinar;
    int tiempoCoccion = 5000;

protected:
    Agarrable *item;
};

#endif //HORNALLA_H
