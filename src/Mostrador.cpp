#include "../includes/Mostrador.h"
#include "../includes/Definiciones.h"
#include "../includes/Ingrediente.h"
#include "../includes/Plato.h"
#include <iostream>

Mostrador::Mostrador(sf::Vector2i pos, int rot, sf::Vector2f size) : Espacio(pos, rot) {
	dibujable = false;
	setTipo(TileType::Mostrador);
	setSizeTile(size);
	rectShape.setPosition(getPosicion().x * getSizeTile().x + getSizeTile().x / 2 + offsetX, getPosicion().y * getSizeTile().y + getSizeTile().y / 2 + offsetY);
	item = nullptr;
	
	if (DEBUGLEVEL == 1) {
		rectShape.setOutlineColor(sf::Color::Black);
		rectShape.setOutlineThickness(0.7);
		rectShape.setFillColor(sf::Color::Transparent);
	}
}
	
	Mostrador::~Mostrador() {
	}
	
	bool Mostrador::putAgarrable(Agarrable *ag) {
		if (item == nullptr) {
			item = ag;
			item->setPosicion(sf::Vector2f(getPosicion().x * getSizeTile().x + getSizeTile().x / 2, getPosicion().y * getSizeTile().y + getSizeTile().y / 2));
			return true;
		} else if (!item->getIsIngrediente() && ag->getIsIngrediente()) {
			Plato *p = (Plato *)item;
			Ingrediente *ing = (Ingrediente *)ag;
			ing->setPosicion(sf::Vector2f(getPosicion().x * getSizeTile().x + getSizeTile().x / 2, getPosicion().y * getSizeTile().y + getSizeTile().y / 2));
			p->pushIngrediente(*ing);
			return true;
		}
		return false;
	}
	
	Agarrable *Mostrador::popAgarrable() {
		Agarrable *r = item;
		if (item != nullptr) {
			item = nullptr;
		}
		return r;
	}
	
	void Mostrador::dibujar(sf::RenderWindow *w) {
		if (dibujable || DEBUGLEVEL == 1) {
			w->draw(rectShape);
		}
		if (item != nullptr)
			item->dibujar(w);
	}
	
	Agarrable *Mostrador::getAgarrable() {
		return item;
	}
