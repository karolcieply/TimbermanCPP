#include "Classes.h"
Tree::Tree(int branchPosition):Object()
{
	size = sf::Vector2f(3*windowWidth/5.f,windowHeight/7.f);
	position = sf::Vector2f((windowWidth / 2.f)-size.x/2.f, 0);
	size.x = 10;
	this->branchPosition = branchPosition;
}
Tree::Tree():Object()
{
	size = sf::Vector2f(3*windowWidth/5.f,windowHeight/7.f);
	position = sf::Vector2f((windowWidth / 2.f)-size.x/2.f, 0);
	this->branchPosition =1;
}

void Tree::MoveDown(int multiplier) {
	this->position.y += multiplier*windowHeight / 7.f;
	std::cout << this->position.y;
}
void Tree::Draw(sf::RenderWindow& window)
{
	log = sf::RectangleShape(size);
	log.setPosition(position);
	window.draw(log);
	//window.display();
}