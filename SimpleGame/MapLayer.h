#pragma once
#include "Tile.h"
#include "GameObject.h"

#include "json.hpp"
using json = nlohmann::json;

#include <vector>
#include <string>

class MapLayer {
public:
	int widthInTiles;
	int heightInTiles;

	std::vector<int> tilePositions;
	bool isVisible;
	std::string name;
	std::string type;
	std::vector<GameObject> objects;
private:

	//Functions
public:
	MapLayer(json &layerJson);
	std::string GetLayerType();
	int GetNumberOfTilesInLayer();
private:

};