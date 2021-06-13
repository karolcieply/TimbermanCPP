#include "Classes.h"
Object::Object() {}
Object::Object(sf::Vector2f size, sf::Vector2f position) {
	this->size = size;
	this->position = position;
}
