#ifndef MANEJADOR_PUNTAJES_H
#define MANEJADOR_PUNTAJES_H

#include "Puntaje.h"
#include <list>
#include <string>

class ManejadorPuntajes {
private:
    std::string pathArchivo;

public:
    ManejadorPuntajes(std::string path);
    ~ManejadorPuntajes();
    /**
    En el caso que no haya ningun puntaje con ese nombre, se crea uno.
    Y en el caso que si haya, se escribe solo el que tiene mayor puntaje.
    */
    void escribirPuntaje(Puntaje pun);
    std::list<Puntaje> listarPuntajes();
};

#endif