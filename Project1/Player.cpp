#include "Classes.h"
Player::Player():Object(){
	SetSize(sf::Vector2f(windowHeight/7.f,windowHeight/7.f));
	SetPosition(sf::Vector2f((windowWidth / 2.f) - (3*windowWidth / 10.f), windowHeight*5.f/7.f));
	playerShape.setSize(GetSize());
}
bool Player::LoadTexture(){
	if(!texture.loadFromFile("./resources/timberman2.png")||!textureIdle.loadFromFile("./resources/timberman1.png"))return false;
	return true;
}
void Player::Draw(sf::RenderWindow& window){
	playerShape.setPosition(GetPosition());
	if (isRight)playerShape.setScale(-1,1);
	else playerShape.setScale(1,1);
	if (clock.getElapsedTime().asSeconds() < 0.1f)
		playerShape.setTexture(&texture);
	else
		playerShape.setTexture(&textureIdle);
	window.draw(playerShape);
}
void Player::setRight(bool isRight) {
	clock.restart();
	if (isRight) {
		this->SetPosition(sf::Vector2f((windowWidth / 2.f) + (3*windowWidth / 10.f), windowHeight*5.f/7.f));
		this->isRight = isRight;
	}
	else if (!isRight) {
		this->SetPosition(sf::Vector2f((windowWidth / 2.f) - (3*windowWidth / 10.f), windowHeight*5.f/7.f));
		this->isRight = isRight;
	}
}
