#include <iostream>
#include <fstream>

#include <string>
#include "Game.h"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Main.hpp"

#include "Tile.h"
#include "Tileset.h"
#include "Tilemap.h"

#include "json.hpp"
using json = nlohmann::json;

int main() {
	//std::ifstream i("Tilesets/Data/grass64x64.json");
	std::ifstream i("Levels/Level1.json");
	json j;
	i >> j;
	std::cout << j << std::endl;

	//Tileset tileset(j);
	Tilemap tilemap(j);
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");

	window.setPosition(sf::Vector2i(10, 50));

	window.setTitle("SFML Window");

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}


		//Clear the window
		window.clear(sf::Color::Black);

		//Draw everything here
		//window.draw(tileset.tiles[41]);
		tilemap.DrawMap(window);

		//end the current frame
		window.display();

	}
}

/*int main() {
	std::string characterPath = "C:\\Users\\Jarvis\\Pictures\\GameCharacter.png";
	std::string groundPath = "C:\\Users\\Jarvis\\Pictures\\Ground.png";

	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	window.setPosition(sf::Vector2i(10, 50));

	window.setTitle("SFML Window");

	sf::Vector2u size = window.getSize();
	unsigned int width = size.x;
	unsigned int height = size.y;

	
	sf::Texture characterTexture;
	if (!characterTexture.loadFromFile(characterPath)) {
		std::cout << "Sorry there was an error trying to find this file!" << std::endl;
	}
	sf::Sprite character = sf::Sprite(characterTexture);

	sf::Texture groundTexture;
	if (!groundTexture.loadFromFile(groundPath)) {
		std::cout << "Sorry there was an error trying to find this file!" << std::endl;
	}
	sf::Sprite ground = sf::Sprite(groundTexture);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			character.move(-0.2, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			character.move(0.2, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			character.move(0, 0.2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			character.move(0, -0.2);
		}
		

		//Clear the window
		window.clear(sf::Color::Black);

		//Draw everything here
		window.draw(ground);
		window.draw(character);

		//end the current frame
		window.display();

	}

	return 0;
}*/