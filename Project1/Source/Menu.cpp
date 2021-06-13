#include "Classes.h"
Menu::Menu():Object(sf::Vector2f(windowWidth,windowHeight),sf::Vector2f(0,0)){
	start = sf::RectangleShape(sf::Vector2f(windowWidth/ 2.f, windowHeight / 10.f));
	topScores = sf::RectangleShape(sf::Vector2f(windowWidth/ 2.f, windowHeight / 10.f));
	rules = sf::RectangleShape(sf::Vector2f(windowWidth/ 7.5f, windowWidth/ 7.5f));
	shop = sf::RectangleShape(sf::Vector2f(windowWidth / 2.f, windowHeight / 10.f));
	exit = sf::RectangleShape(sf::Vector2f(windowWidth/ 7.5f, windowWidth/ 7.5f));


	start.setPosition(windowWidth /2.f-(windowWidth/4.f), windowHeight*(1/5.f));
	topScores.setPosition(windowWidth /2.f-(windowWidth/4.f), windowHeight*(3/5.f));
	shop.setPosition(windowWidth /2.f-(windowWidth/4.f), windowHeight*(2/5.f));
	exit.setPosition(windowWidth-windowWidth/50.f-windowWidth/7.5f, windowWidth/50.f);
	rules.setPosition(windowWidth/50.f, windowWidth/50.f);

	start.setTexture(&resManager.GetTexture("start"));
	topScores.setTexture(&resManager.GetTexture("highScore"));
	exit.setTexture(&resManager.GetTexture("smallExitButton"));
	shop.setTexture(&resManager.GetTexture("shopButton"));
	rules.setTexture(&resManager.GetTexture("rulesButton"));
}
void Menu::Draw(sf::RenderWindow& window)
{
	window.draw(start);
	window.draw(topScores);
	window.draw(exit);
	window.draw(shop);
	window.draw(rules);
}
int Menu::OnClick(sf::Vector2i mousePosition)
{
	if (start.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) return 1;
	else if (exit.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) return 2;
	else if (topScores.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) return 3;
	else if (rules.getGlobalBounds().contains(mousePosition.x, mousePosition.y))return 4;
	else if (shop.getGlobalBounds().contains(mousePosition.x, mousePosition.y))return 5;
}
