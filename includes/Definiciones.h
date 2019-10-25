#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#define SCALE_X 4
#define SCALE_Y 4
#define TILEWIDTH 32
#define TILEHEIGHT 32
#define SEPARACION 4

/* 
Enum enumera del 0 para adelante cada elemento.
Por ejemplo aca los elementos valen:
 - Suelo = 0
 - Mesada = 1
 - Hormalla = 2
 - ETC
*/
enum TileType {
    Suelo,
    Mesada,
    Hornalla,
    Heladera,
};
enum IngredienteType {
    Lechuga,
    Tomate,
    PanArriba,
    PanAbajo
};

#endif // DEFINICIONES_H
