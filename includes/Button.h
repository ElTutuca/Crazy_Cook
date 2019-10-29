#ifndef BOTON_H
#define BOTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button{
private:
	/*
	unsigned short buttonState;
	*/ 
	sf::RectangleShape shape;
	sf::Text text;
	sf::Color buttonColor;
	sf::Font font;
	
public:
	Button(float Pos_x, float Pos_y, float Ancho, float Largo, std::string Text, sf::Color buttonColor, sf::Font font);
	
	~Button();
	
	float getCenterX();
	float getCenterY();
	
	bool isPressed(sf::RenderWindow *w);
	
	void render(sf::RenderWindow *w);
};

#endif
