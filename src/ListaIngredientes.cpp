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
void ListaIngredientes::setEstadoIngredientes(std::list<IngredienteType> lista) {
    std::list<Ingrediente>::iterator itListaIng;
    for (itListaIng = listaIngr.begin(); itListaIng != listaIngr.end(); itListaIng++) {
        // Itero y busco por toda la lista de IngredienteType y busco si esta la que forma parte de esta lista
        bool found = (std::find(lista.begin(), lista.end(), itListaIng->getIngredienteType()) != lista.end());
        cambiarEstado(*itListaIng, found);
    }
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
        str = *itEstado ? str + "  # Listo #" : str;
        listaR.push_back(str);
        std::advance(itEstado, 1);
    }
    listaR.reverse();
    return listaR;
}
void ListaIngredientes::setPlato(Plato p) {
    int size = p.size();
    for (int i = 0; i < size; i++) {
        listaIngr.push_back(p.popIngrediente());
        listaEstados.push_back(false);
    }
}