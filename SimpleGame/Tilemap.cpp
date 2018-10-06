#include "Tilemap.h"
#include <fstream>
#include <iostream>

Tilemap::Tilemap(json &mapJson) {
	this->widthInTiles = mapJson["width"];
	this->heightInTiles = mapJson["height"];
	this->tileWidth = mapJson["tilewidth"];
	this->tileHeight = mapJson["tileheight"];

	//Load in the tileset(s)
	std::vector<json> tempTilesetSourceVector = 
		mapJson["tilesets"].get<std::vector<json>>();
	std::cout << "tempTilesetSourceVector size is: " << tempTilesetSourceVector.size() << std::endl;
	for (int i = 0; i < tempTilesetSourceVector.size(); i++) {
		std::cout << i << std::endl;
		std::string tilesetSource = tempTilesetSourceVector[i]["source"].get<std::string>();
		//We do this because we don't want 3 characters at the beginning
		//of the string (it will give us wrong path)
		tilesetSource = tilesetSource.substr(3);
		std::ifstream input(tilesetSource);
		json tempJson;
		input >> tempJson;
		//THIS CAUSES THE ERROR
		this->tilesets.push_back(Tileset(tempJson));
	}

	//Load in the MapLayers
	std::vector<json> tempLayerVector = mapJson["layers"].get<std::vector<json>>();
	for (int i = 0; i < tempLayerVector.size(); i++) {
		this->mapLayers.push_back(MapLayer(tempLayerVector[i]));
	}

	//Get all tiles from tileset so it is easier to use them
	//hopefully this doesnt break
	for (int i = 0; i < this->tilesets.size(); i++) {
		for (int j = 0; j < this->tilesets[i].numOfTiles - 1; j++) {
			this->tiles.push_back(this->tilesets[i].tiles[j]);
		}
	}
}

void Tilemap::DrawMap(sf::RenderWindow &window) {
	std::vector<MapLayer> &mapLayers = this->mapLayers;
	std::vector<Tile> &tiles = this->tiles;

	int numberOfTilesInLayer;

	int widthInTiles = this->widthInTiles;
	int heightInTiles = this->heightInTiles;
	int tileWidth = this->tileWidth;
	int tileHeight = this->tileHeight;

	int x = 0;
	int y = 0;

	for (int i = 0; i < this->mapLayers.size(); i++) {
		std::vector<int> &tilePositions = mapLayers[i].tilePositions;
		numberOfTilesInLayer = tilePositions.size();

		if (this->mapLayers[i].type == "tilelayer") {
			//Now loop through the tile position data to draw them
			for (int j = 0; j < numberOfTilesInLayer; i++) {
				//Check if we need to start a new row
				if (j + 1 % widthInTiles == 0) {
					y += tileHeight;
					x = 0;
				}

				//We have subtract one from this to make it correct
				tilePositions[j] -= 1;
				if (tilePositions[j] != -1) {
					//Draw Tiles
					Tile tile = tiles[tilePositions[j]];
					tile.setPosition(x, y);
					window.draw(tile);
				}
				x += tileWidth;
			}
		}
	}
}