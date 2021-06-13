#include "Classes.h"
Rules::Rules()
{
	rulesScreen.setSize(sf::Vector2f(windowWidth/1.5f, windowHeight/1.25f));
	rulesScreen.setOrigin(sf::Vector2f(rulesScreen.getSize().x/2.f, rulesScreen.getSize().y/2.f));
	rulesScreen.setPosition(sf::Vector2f(windowWidth/2.F , windowHeight/2.F));
	rulesScreen.setTexture(&resManager.GetTexture("rulesBackground"));

	backToMenu = sf::RectangleShape(sf::Vector2f(windowWidth/ 2.f, windowHeight / 10.f));
	backToMenu.setPosition(windowWidth/2.f-(windowWidth/4.f), windowHeight *(3.5/5.f));
	backToMenu.setTexture(&resManager.GetTexture("menuButton"));
}
void Rules::Draw(sf::RenderWindow& window)
{
	window.draw(rulesScreen);
	window.draw(backToMenu);
}
int Rules::OnClick(sf::Vector2i mousePosition)
{
	if (backToMenu.getGlobalBounds().contains(mousePosition.x,mousePosition.y)) return 1;
}