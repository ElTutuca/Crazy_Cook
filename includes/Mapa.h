#ifndef MAPA_H
#define MAPA_H

#include "Espacio.h"
#include "ManejadorClientes.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <vector>

class Mapa {
private:
    std::vector<std::vector<int>> nivel;
    std::vector<std::vector<int>> rotacion;
    std::vector<std::vector<Espacio *>> espacios;
    std::list<IngredienteType> ingPresentes;
    std::list<int> cantIngPresentes;
    sf::Sprite fondo;

public:
    Mapa(std::vector<std::vector<int>> niv, std::vector<std::vector<int>> rot, sf::Texture *tMapa, ManejadorClientes *manCli);
    ~Mapa();
	sf::Music music;
    void dibujar(sf::RenderWindow *w);
    Espacio *getEspacioAt(int x, int y);
    void setLayout(std::vector<std::vector<int>> niv, std::vector<std::vector<int>> rot);
    void actualizarIngPresentes(IngredienteType ing, bool agregado);
    std::list<IngredienteType> *getIngPresentes();
    int getAncho();
    int getAlto();
	void playMusic(bool play);
};

#endif // MAPA_H
