#include "../includes/Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

Button::Button(float Pos_x, float Pos_y, float Ancho, float Largo, sf::Color buttonColor) {
    this->shape.setPosition(sf::Vector2f(Pos_x, Pos_y));
    this->shape.setSize(sf::Vector2f(Ancho, Largo));
    this->shape.setFillColor(buttonColor);
}

Button::~Button() {
}

float Button::getCenterX() {
    return (this->shape.getPosition().x + ((this->shape.getSize().x) / 2));
}

float Button::getCenterY() {
    return (this->shape.getPosition().y + ((this->shape.getSize().y) / 2));
}

bool Button::isPressed(sf::RenderWindow *w) {
    if (this->shape.getPosition().x<sf::Mouse::getPosition(*w).x &(this->shape.getPosition().x + this->shape.getSize().x)> sf::Mouse::getPosition(*w).x & this->shape.getPosition().y<sf::Mouse::getPosition(*w).y &(this->shape.getPosition().y + this->shape.getSize().y)> sf::Mouse::getPosition(*w).y) {
        return true;
    }
    return false;
}

void Button::render(sf::RenderWindow *w) {
    w->draw(this->shape);
}
