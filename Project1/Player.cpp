#include "Classes.h"
Player::Player():Object(){
	size = sf::Vector2f(windowWidth/5.f,windowHeight/7.f);
	position = sf::Vector2f((windowWidth/2.f)+(windowWidth/10.f),windowHeight-size.y-windowHeight/10.f);
}
void Player::Draw(sf::RenderWindow& window){
	sf::RectangleShape playerShape(size);
	playerShape.setPosition(position);
	//window.clear();
	window.draw(playerShape);
	//window.display();
}
void Player::setRight(bool isRight) {
	if (isRight) {
		this->position = sf::Vector2f((windowWidth / 2.f) + (windowWidth / 10.f), windowHeight*5.f/7.f);
		this->isRight = isRight;
		std::cout << this->isRight;
	}
	else if (!isRight) {
		this->position = sf::Vector2f((windowWidth / 2.f) - (windowWidth / 10.f) - size.x, windowHeight*5.f/7.f);
		this->isRight = isRight;
		std::cout << this->isRight;
	}
}