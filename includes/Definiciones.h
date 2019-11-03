#ifndef DEFINICIONES_H
#define DEFINICIONES_H

extern float SCALE;
extern int SCREENWIDTH;
extern int SCREENHEIGHT;
extern int MAPWIDTH;
extern int MAPHEIGHT;
extern int PANEWIDTH;
extern const int TILEWIDTH;
extern const int TILEHEIGHT;
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
    Heladera,
    Tacho,
    Rejilla,
	Mostrador
};
enum IngredienteType {
    PanAbajo,
    PanArriba,
    HamburgesaCocinada,
    Lechuga,
    Tomate,
    HamburgesaCruda
};

#endif // DEFINICIONES_H
