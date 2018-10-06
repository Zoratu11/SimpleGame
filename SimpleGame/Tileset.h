#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.h"

#include "json.hpp"
using json = nlohmann::json;

class Tileset {
public:
	int numOfColumns;
	int height;
	int width;
	int margin;
	int spacing;
	int numOfTiles;
	int tileHeight;
	int tileWidth;

	std::string name;
	std::string tilesetImagePath;
	
	std::vector<Tile> tiles;
	//I think we have to hold the textures in memory or the sprite will be blank
	sf::Texture tilesetTexture;
private:

	//Functions
public:
	Tileset(json &tilesetJson);
private:
	void GetTilesFromTilesetImage();
};