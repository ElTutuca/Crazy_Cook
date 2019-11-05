#include "../includes/ListaIngredientes.h"

ListaIngredientes::ListaIngredientes() {
}
ListaIngredientes::ListaIngredientes(Plato p) {
    int size = p.size();
    for (int i = 0; i < size; i++) {
        listaIngr.push_back(p.popIngrediente());
        listaEstados.push_back(false);
    }
}
ListaIngredientes::ListaIngredientes(std::list<Ingrediente> listaIng) {
    listaIngr = listaIng;
}
ListaIngredientes::~ListaIngredientes() {
}
void ListaIngredientes::tickIngrediente(Ingrediente ing) {
    cambiarEstado(ing, true);
}
void ListaIngredientes::untickIngrediente(Ingrediente ing) {
    cambiarEstado(ing, false);
}

void ListaIngredientes::cambiarEstado(Ingrediente ing, bool estado) {
    std::list<Ingrediente>::iterator itIngrediente;
    int i = 0;
    for (itIngrediente = listaIngr.begin(); itIngrediente != listaIngr.end(); itIngrediente++) {
        if (*itIngrediente == ing) {
            std::list<bool>::iterator it = listaEstados.begin();
            std::advance(it, i);
            *it = estado;
            break;
        }
        i++;
    }
}

std::list<std::string> ListaIngredientes::getStrings() {
    std::list<std::string> listaR;
    std::list<Ingrediente>::iterator itIngrediente;
    std::list<bool>::iterator itEstado = listaEstados.begin();
    for (itIngrediente = listaIngr.begin(); itIngrediente != listaIngr.end(); itIngrediente++) {
        if (*itEstado == true) {
            listaR.push_back("########");
        } else {
            std::string str;
            if (itIngrediente->getIngredienteType() == IngredienteType::Lechuga)
                str = "Lechuga";
            else if (itIngrediente->getIngredienteType() == IngredienteType::Tomate)
                str = "Tomate";
            else if (itIngrediente->getIngredienteType() == IngredienteType::PanAbajo)
                str = "Pan de abajo";
            else if (itIngrediente->getIngredienteType() == IngredienteType::PanArriba)
                str = "Pan de arriba";
            else if (itIngrediente->getIngredienteType() == IngredienteType::HamburgesaCocinada)
                str = "Hamburguesa";
            listaR.push_back(str);
        }
        std::advance(itEstado, 1);
    }
    return listaR;
}