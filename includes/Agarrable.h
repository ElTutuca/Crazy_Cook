#ifndef AGARRABLE_H
#define AGARRABLE_H
#include <SFML/Graphics.hpp>

class Agarrable {
private:
    bool isIngrediente;

public:
    Agarrable(sf::Vector2f pos, float ang, sf::Texture *tex, bool ingrediente);
    Agarrable();
    ~Agarrable();
    virtual void setPosicion(sf::Vector2f pos);
    sf::Vector2f getPosicion();
    float getRotacion();
    bool getIsIngrediente();
    virtual void dibujar(sf::RenderWindow *w);
    virtual void agarrado(float x, float y, float angulo, float anchoChef);

protected:
    float angulo;
    // Posicion en termios relativos a la ventana
    sf::Vector2f posicion;
    // Tamanio sin escala
    sf::Vector2f tamanio;
    sf::Sprite spt;
    int offsetX, offsetY;
    void setIsIngrediente(bool t);
    void actualizar();
};

#endif