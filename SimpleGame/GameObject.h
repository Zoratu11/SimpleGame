#pragma once
#include "SFML/Graphics.hpp"
#include "json.hpp"
using json = nlohmann::json;

class GameObject {
public:
	int height;
	int width;
	float rotation;
	int x;
	int y;
	bool isVisible;
private:

	//Functions
public:
	sf::Rect<float> GetBoundingRect();
	GameObject(json &objectJson);
private:

};