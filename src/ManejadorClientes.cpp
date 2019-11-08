#include "../includes/ManejadorClientes.h"
#include <cstdlib>
#include <ctime>

ManejadorClientes::ManejadorClientes() {
    manRecetas.setPath("RecetasG.txt");
    sf::Texture t1, t2, t3;
    t1.loadFromFile("resources/Imagenes/Cliente_1.png");
    t2.loadFromFile("resources/Imagenes/Cliente_2.png");
    t3.loadFromFile("resources/Imagenes/Cliente_3.png");
    tClientes[0] = t1;
    tClientes[1] = t2;
    tClientes[2] = t3;
    std::srand(std::time(NULL));
    esperaProxCliente = rand() % 15 + 11;
    dt.restart();
}
ManejadorClientes::ManejadorClientes(Mapa *map) {
    manRecetas.setPath("RecetasG.txt");
    sf::Texture t1, t2, t3;
    t1.loadFromFile("resources/Imagenes/Cliente_1.png");
    t2.loadFromFile("resources/Imagenes/Cliente_2.png");
    t3.loadFromFile("resources/Imagenes/Cliente_3.png");
    tClientes[0] = t1;
    tClientes[1] = t2;
    tClientes[2] = t3;
    std::srand(std::time(NULL));
    esperaProxCliente = rand() % 15 + 11;
    dt.restart();
    // ManejadorClientes();
    setMapa(map);
}
ManejadorClientes::~ManejadorClientes() {
}
void ManejadorClientes::correr() {
    if ((empty() && dt.getElapsedTime().asSeconds() > 5) || (size() <= 2 && dt.getElapsedTime().asSeconds() > esperaProxCliente)) {
        // 15 - 25
        esperaProxCliente = rand() % 15 + 11;
        Plato platoRand = manRecetas.getPlato(rand() % manRecetas.getCantidadPlatos());
        Cliente c(&tClientes[rand() % 3], platoRand, platoRand.size() * 30);
        pushCliente(c);
        dt.restart();
    }
    if (!empty()) {
        int tam = size();
        std::list<IngredienteType> listaIng = map->getIngPresentes();
        for (int i = 0; i < tam; i++) {
            Cliente aux = colaClientes.front();
            colaClientes.pop();
            aux.getListaIngredientes()->setEstadoIngredientes(listaIng);
            colaClientes.push(aux);
        }
    }
}
void ManejadorClientes::dibujar(sf::RenderWindow *w) {
    correr();
    int tam = size();
    for (int i = 0; i < tam; i++) {
        Cliente front = colaClientes.front();
        colaClientes.pop();
        front.mostrar(w);
        colaClientes.push(front);
    }
}
void ManejadorClientes::pushCliente(Cliente cli) {
    if (colaClientes.size() < 3) {
        cli.setOffset(0, cli.getSize().y * size());
        colaClientes.push(cli);
    }
}
Cliente ManejadorClientes::popCliente() {
    if (!empty()) {
        Cliente r = colaClientes.front();
        colaClientes.pop();
        for (int i = 0; i < size(); i++) {
            Cliente aux = colaClientes.front();
            colaClientes.pop();
            pushCliente(aux);
        }
        return r;
    } else {
        throw 404;
    }
}
bool ManejadorClientes::empty() {
    return colaClientes.empty();
}
int ManejadorClientes::size() {
    return colaClientes.size();
}
Cliente ManejadorClientes::front() {
    return colaClientes.front();
}
void ManejadorClientes::setMapa(Mapa *map) {
    this->map = map;
}