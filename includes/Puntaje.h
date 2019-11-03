#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <fstream>
#include <list>
#include <string>

class Puntaje {
private:
    int puntos;
    std::string nombre;

public:
    Puntaje(std::string nombre, int puntos);
    ~Puntaje();
    int getPuntos();
    void setPuntos(int puntos);
    std::string getNombre();

    bool operator<(const Puntaje s1);
    bool operator>(const Puntaje s1);
    bool operator<=(const Puntaje s1);
    bool operator>=(const Puntaje s1);
    bool operator==(const Puntaje s1);
    bool operator!=(const Puntaje s1);
};

#endif