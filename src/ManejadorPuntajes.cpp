#include "../includes/ManejadorPuntajes.h"
#include "../includes/Definiciones.h"
#include <fstream>
ManejadorPuntajes::ManejadorPuntajes(std::string path) {
    pathArchivo = path;
    puntosActual = 0;

    font.loadFromFile("resources/Fuentes/OpenSans-Light.ttf");
    txtPuntos.setFont(font);
    txtPuntos.setFillColor(sf::Color::Black);
    txtPuntos.setCharacterSize(24);
    txtPuntos.setOutlineThickness(1);
    txtPuntos.setScale(sf::Vector2f(0.3, 0.3));
}
ManejadorPuntajes::~ManejadorPuntajes() {
}
void ManejadorPuntajes::actualizarPosicion() {
    txtPuntos.setPosition(sf::Vector2f(MAPWIDTH - 60, MAPHEIGHT - 20));
}
void ManejadorPuntajes::escribirPuntaje(std::string nombre) {
    std::list<Puntaje> listaPuntajes = listarPuntajes();
    bool encontrado = false;
    // Un iterator sirve para iterar en un conjunto de elementos
    std::list<Puntaje>::iterator itPuntaje;
    // Itera desde el comienzo (begin), hasta que termina (end)
    for (itPuntaje = listaPuntajes.begin(); itPuntaje != listaPuntajes.end(); itPuntaje++) {
        if (itPuntaje->getNombre() == nombre) {
            encontrado = true;
            if (puntosActual > itPuntaje->getPuntos()) {
                itPuntaje->setPuntos(puntosActual);
            }
        }
    }
    if (!encontrado)
        listaPuntajes.push_back(Puntaje(nombre, puntosActual));

    listaPuntajes.sort();
    listaPuntajes.reverse();
    std::ofstream outArchivo(pathArchivo);

    std::list<Puntaje>::iterator it;
    int i = 0;
    for (it = listaPuntajes.begin(); it != listaPuntajes.end(); it++) {
        if (i++ < listaPuntajes.size() - 1)
            outArchivo << it->getNombre() << " " << it->getPuntos() << "\n";
        else
            outArchivo << it->getNombre() << " " << it->getPuntos();
    }
    outArchivo.close();
}
std::list<Puntaje> ManejadorPuntajes::listarPuntajes() {
    std::list<Puntaje> listaPuntajes;
    std::ifstream inArchivo(pathArchivo);
    std::string lineaLeer;
    // Lee el archivo
    if (inArchivo.is_open()) {
        // Loopea por todo el archivo
        while (!inArchivo.eof()) {
            getline(inArchivo, lineaLeer);
            if (lineaLeer != "") {
                std::string nombre = lineaLeer.substr(0, lineaLeer.find(" "));
                int puntos = std::stoi(lineaLeer.substr(lineaLeer.find(" ") + 1, lineaLeer.size() - lineaLeer.find(" ")));
                listaPuntajes.push_back(Puntaje(nombre, puntos));
            }
        }
        inArchivo.close();
    } else {
        throw "Error al abrir el archivo";
    }
    return listaPuntajes;
}
void ManejadorPuntajes::addPuntos(int puntos) {
    puntosActual += puntos;
}

void ManejadorPuntajes::dibujar(sf::RenderWindow *w) {
    txtPuntos.setFont(font);
    txtPuntos.setString("Puntos: " + std::to_string(puntosActual));
    w->draw(txtPuntos);
}