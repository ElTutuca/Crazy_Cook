#ifndef BOTON_H
#define BOTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Button{
private:
	/*
	unsigned short buttonState;
	*/ 
	sf::RectangleShape shape;
	sf::Color buttonColor;
	sf::Sound sonidoBoton;
	sf::SoundBuffer bufferBoton;
	
public:
	Button(float Pos_x, float Pos_y, float Ancho, float Largo, sf::Color buttonColor);
	
	~Button();
	
	float getCenterX();
	float getCenterY();
	
	bool isPressed(sf::RenderWindow *w);
	
	void render(sf::RenderWindow *w);
};

#endif
