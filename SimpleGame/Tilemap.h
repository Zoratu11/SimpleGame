#pragma once
#include <vector>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MapLayer.h"
#include "Tileset.h"

#include "json.hpp"
using json = nlohmann::json;

class Tilemap {
public:
	std::vector<Tileset> tilesets;
	//Waste of memory I know but it will work for now
	std::vector<Tile> tiles;

	int tileWidth;
	int tileHeight;
	int heightInTiles;
	int widthInTiles;
	int numOfLayers;

	std::vector<MapLayer> mapLayers;
private:

	//Functions
public:
	Tilemap(json &mapJson);
	void DrawMap(sf::RenderWindow &window);
private:

};