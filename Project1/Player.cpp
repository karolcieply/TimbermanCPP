#include "Classes.h"
Player::Player():Object(){
	SetSize(sf::Vector2f(windowWidth/5.f,windowHeight/7.f));
	SetPosition(sf::Vector2f((windowWidth / 2.f) + (windowWidth / 10.f), windowHeight*5.f/7.f));
}
bool Player::LoadTexture(){
	textureLeft.loadFromFile("./resources/playerleft.png");
	textureRight.loadFromFile("./resources/playerright.png");
	return true;
}
void Player::Draw(sf::RenderWindow& window){
	sf::RectangleShape playerShape(GetSize());
	playerShape.setPosition(GetPosition());
	if (isRight)playerShape.setTexture(&textureRight);
	else playerShape.setTexture(&textureLeft);
	window.draw(playerShape);
}
void Player::setRight(bool isRight) {
	if (isRight) {
		this->SetPosition(sf::Vector2f((windowWidth / 2.f) + (windowWidth / 10.f), windowHeight*5.f/7.f));
		this->isRight = isRight;
	}
	else if (!isRight) {
		this->SetPosition(sf::Vector2f((windowWidth / 2.f) - (windowWidth / 10.f) - GetSize().x, windowHeight*5.f/7.f));
		this->isRight = isRight;
	}
}