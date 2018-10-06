#pragma once

#include "SFML\Graphics.hpp"
#include <string>

class Tile : public sf::Sprite {
//Variables
public:
	int id;
	int xPos;
	int yPos;
private:

//Functions
public:
	Tile(const sf::Texture &texture, const sf::IntRect &rectangle) :
		sf::Sprite(texture, rectangle) {};
private:

};