#include "Classes.h"
#include <random>
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0,30);
Tree::Tree(int branchPosition):Object()
{
	SetSize(sf::Vector2f(3*windowWidth/5.f,windowHeight/7.f));
	SetPosition(sf::Vector2f((windowWidth / 2.f)-GetSize().x/2.f, 0));
	this->branchPosition = branchPosition;
}
void Tree::MoveDown(int multiplier) {
	SetPosition(sf::Vector2f(GetPosition().x,GetPosition().y+multiplier*windowHeight/7.f));
}
void Tree::Draw(sf::RenderWindow& window)
{
	log = sf::RectangleShape(GetSize());
	log.setPosition(GetPosition());
	if (branchPosition == 0)
		log.setTexture(&resManager.GetTexture("TreeLeft"));
	if (branchPosition == 1)
		log.setTexture(&resManager.GetTexture("Tree"));
	if (branchPosition == 2)
		log.setTexture(&resManager.GetTexture("TreeRight"));
	window.draw(log);
}
void Tree::RollBranch() {
	int tmp = distribution(generator);
	if (tmp <= 13)
		this->branchPosition = 0;
	else if (tmp >= 16)
		this->branchPosition = 2;
	else
		this->branchPosition = 1;
	return;
}