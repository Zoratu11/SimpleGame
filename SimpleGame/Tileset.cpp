#include "Tileset.h"
#include <fstream>
#include <iostream>

Tileset::Tileset(json &tilesetJson) {
	this->numOfColumns = tilesetJson["columns"];
	this->tilesetImagePath = "Tilesets/" + tilesetJson["image"].get<std::string>().substr(3);
	this->height = tilesetJson["imageheight"];
	this->width = tilesetJson["imagewidth"];
	this->margin = tilesetJson["margin"];
	this->spacing = tilesetJson["spacing"];
	this->name = tilesetJson["name"].get<std::string>();
	this->numOfTiles = tilesetJson["tilecount"];
	this->tileHeight = tilesetJson["tileheight"];
	this->tileWidth = tilesetJson["tilewidth"];

	std::cout << tilesetImagePath << std::endl;

	//Set the tilesetTexture
	this->tilesetTexture = sf::Texture();
	if (!this->tilesetTexture.loadFromFile(this->tilesetImagePath)) {
		std::cout << "Sorry the file for the texture could not be read!!" << std::endl;
	}

	GetTilesFromTilesetImage();
}

void Tileset::GetTilesFromTilesetImage() {
	int tileWidth = this->tileWidth;
	int tileHeight = this->tileHeight;
	int numOfTiles = this->numOfTiles;
	int numOfColumns = this->numOfColumns;

	int x = 0;
	int y = 0;
	for (int i = 0; i < numOfTiles; i++) {

		//Now put a part of the texture into the tiles vector
		Tile tile(this->tilesetTexture, sf::IntRect(x, y, tileWidth, tileHeight));
		tile.id = i + 1;
		this->tiles.push_back(tile);

		x += tileWidth;
		//If i+1 is a multiple of 8 (which means that is one complete row because there are 8 tiles in a row) go to next row
		if ((i + 1) % numOfColumns == 0) {
			y += tileHeight;
			x = 0;
		}
	}
}