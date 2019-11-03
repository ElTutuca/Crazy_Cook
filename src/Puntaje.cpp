#include "../includes/Puntaje.h"

Puntaje::Puntaje(std::string nombre, int puntos) {
    this->nombre = nombre;
    this->puntos = puntos;
}

Puntaje::~Puntaje() {
}

int Puntaje::getPuntos() {
    return puntos;
}
std::string Puntaje::getNombre() {
    return nombre;
}

void Puntaje::setPuntos(int puntos) {
    this->puntos = puntos;
}
bool Puntaje::operator<(const Puntaje s1) {
    return puntos < s1.puntos;
}
bool Puntaje::operator>(const Puntaje s1) {
    return puntos > s1.puntos;
}
bool Puntaje::operator<=(const Puntaje s1) {
    return puntos <= s1.puntos;
}
bool Puntaje::operator>=(const Puntaje s1) {
    return puntos >= s1.puntos;
}
bool Puntaje::operator==(const Puntaje s1) {
    return (puntos == s1.puntos && nombre == s1.nombre);
}
bool Puntaje::operator!=(const Puntaje s1) {
    return !(*this == s1);
}
