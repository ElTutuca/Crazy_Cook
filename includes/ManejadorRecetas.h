#ifndef MANEJADOR_RECETAS_H
#define MANEJADOR_RECETAS_H
#include "Plato.h"
#include <list>
#include <string>

class ManejadorRecetas {
private:
    std::string pathArchivo;

public:
    ManejadorRecetas(std::string path);
    ~ManejadorRecetas();
    std::list<Plato> listarPlatos();
    Plato getPlato(int indice);
	int getCantidadPlatos();
};

#endif
