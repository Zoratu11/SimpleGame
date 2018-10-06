#include "GameObject.h"

GameObject::GameObject(json &objectJson) {
	this->width = objectJson["width"];
	this->height = objectJson["height"];
	this->x = objectJson["x"];
	this->y = objectJson["y"];
	this->rotation = objectJson["rotation"].get<float>();
	this->isVisible = objectJson["visible"];
}

sf::Rect<float> GameObject::GetBoundingRect() {
	sf::Vector2f size(this->width, this->height);
	sf::Vector2f position(this->x, this->y);

	return sf::Rect<float>(
		position.x, position.y,
		size.x, size.y
		);
}
