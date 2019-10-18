#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#define SCALE_X 3
#define SCALE_Y 3

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
    Hornalla
};
enum IngredienteType {
    Lechuga,
    Tomate,
    PanArriba,
    PanAbajo
};

#endif // DEFINICIONES_H
