#ifndef MANEJADOR_PUNTAJES_H
#define MANEJADOR_PUNTAJES_H

#include "Puntaje.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <string>

class ManejadorPuntajes {
private:
    std::string pathArchivo;
    int puntosActual;
    sf::Text txtPuntos;
    sf::Font font;

public:
    ManejadorPuntajes(std::string path);
    ~ManejadorPuntajes();
    /**
    En el caso que no haya ningun puntaje con ese nombre, se crea uno.
    Y en el caso que si haya, se escribe solo el que tiene mayor puntaje.
    */
    void addPuntos(int puntos);
    void escribirPuntaje(std::string nombre);
    std::list<Puntaje> listarPuntajes();
    void actualizarPosicion();

    void dibujar(sf::RenderWindow *w);
};

#endif