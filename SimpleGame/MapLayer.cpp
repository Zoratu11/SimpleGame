#include "MapLayer.h"

MapLayer::MapLayer(json &layerJson) {
	this->type = layerJson["type"].get<std::string>();
	if (this->type == "tilelayer") {
		this->widthInTiles = layerJson["width"];
		this->heightInTiles = layerJson["height"];
		this->tilePositions = layerJson["data"].get<std::vector<int>>();
	}
	else if(this->type == "objectgroup") {
		this->widthInTiles = NULL;
		this->heightInTiles = NULL;

		std::vector<json> tempJsonVector = 
			layerJson["objects"].get<std::vector<json>>();
		for (int i = 0; i < tempJsonVector.size(); i++) {
			this->objects.push_back(GameObject(tempJsonVector[i]));
		}
	}
	
	this->isVisible = layerJson["visible"];
	this->name = layerJson["name"].get<std::string>();
}

std::string MapLayer::GetLayerType() {
	return this->type;
}

int MapLayer::GetNumberOfTilesInLayer() {
	return this->tilePositions.size();
}