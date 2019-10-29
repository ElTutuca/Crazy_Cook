#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#define SCALE_X 4
#define SCALE_Y 4
#define TILEWIDTH 32
#define TILEHEIGHT 32
/*
DEBUGLEVEL = 0 => Sin debug
DEBUGLEVEL = 1 => Con debug
*/
#define DEBUGLEVEL 0
#define degToRad(angleInDegrees) ((angleInDegrees)*M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians)*180.0 / M_PI)

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
    Heladera
};
enum IngredienteType {
    Lechuga,
    Tomate,
    PanArriba,
    PanAbajo,
    HamburgesaCocinada,
    HamburgesaCruda,
};

#endif // DEFINICIONES_H
