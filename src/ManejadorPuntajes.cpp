#include "../includes/ManejadorPuntajes.h"
#include <fstream>
ManejadorPuntajes::ManejadorPuntajes(std::string path) {
    pathArchivo = path;
}
ManejadorPuntajes::~ManejadorPuntajes() {
}
void ManejadorPuntajes::escribirPuntaje(Puntaje pun) {
    std::list<Puntaje> listaPuntajes = listarPuntajes();
    bool encontrado = false;
    // Un iterator sirve para iterar en un conjunto de elementos
    std::list<Puntaje>::iterator itPuntaje;
    // Itera desde el comienzo (begin), hasta que termina (end)
    for (itPuntaje = listaPuntajes.begin(); itPuntaje != listaPuntajes.end(); itPuntaje++) {
        if (itPuntaje->getNombre() == pun.getNombre()) {
            encontrado = true;
            if (pun.getPuntos() > itPuntaje->getPuntos())
                itPuntaje->setPuntos(pun.getPuntos());
            // ? Deberia poner un break? O se rompe??;
        }
    }
    if (!encontrado)
        listaPuntajes.push_back(pun);

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
