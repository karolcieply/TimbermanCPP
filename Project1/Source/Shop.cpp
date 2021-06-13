#include "Classes.h"
Shop::Shop()
{
	//resManager.LoadTexture("TimbermanIdle", TIMBERMAN_IDLE_SPRITE);
	//resManager.LoadTexture("TimbermanChop", TIMBERMAN_CHOP_SPRITE);
	shopScreen.setSize(sf::Vector2f(windowWidth/1.5f, windowHeight/1.25f));
	shopScreen.setOrigin(sf::Vector2f(shopScreen.getSize().x/2.f, shopScreen.getSize().y/2.f));
	shopScreen.setPosition(sf::Vector2f(windowWidth/2.F , windowHeight/2.F));
	shopScreen.setTexture(&resManager.GetTexture("highScoreBackground"));

	backToMenu.setSize(sf::Vector2f(windowWidth/ 2.f, windowHeight / 10.f));
	backToMenu.setPosition(windowWidth/2.f-(windowWidth/4.f), windowHeight *(3.5/5.f));
	backToMenu.setTexture(&resManager.GetTexture("menuButton"));

	chosenSkin.setSize(sf::Vector2f(windowHeight / 3.5f, windowHeight / 3.5f));
	chosenSkin.setOrigin(sf::Vector2f(chosenSkin.getSize().x / 2.f, chosenSkin.getSize().y / 2.f));
	chosenSkin.setPosition(sf::Vector2f(windowWidth / 2.f, windowHeight / 2.f));
	//chosenSkin.setTexture(&resManager.GetTexture("TimbermanIdle"));

	next.setSize(sf::Vector2f(windowWidth/ 7.5f, windowWidth/ 7.5f));
	next.setPosition(sf::Vector2f(windowWidth/2.f,windowHeight/4.f));
	next.setTexture(&resManager.GetTexture("arrowButton"));
	next.setScale(1, 1);
	
	previous.setSize((sf::Vector2f(windowWidth/ 7.5f, windowWidth/ 7.5f)));
	previous.setPosition(sf::Vector2f(windowWidth/2.f,windowHeight/4.f));
	previous.setTexture(&resManager.GetTexture("arrowButton"));
	previous.setScale(-1, 1);
}
void Shop::Draw(sf::RenderWindow& window)
{
	window.draw(shopScreen);
	window.draw(backToMenu);
	window.draw(chosenSkin);
	if (clock.getElapsedTime().asSeconds() < 1)
		chosenSkin.setTexture(&resManager.GetTexture("TimbermanChop"));
	else
		chosenSkin.setTexture(&resManager.GetTexture("TimbermanIdle"));
	if (clock.getElapsedTime().asSeconds() > 2)clock.restart();
	window.draw(next);
	window.draw(previous);
}
int Shop::OnClick(sf::Vector2i mousePosition)
{
	if (backToMenu.getGlobalBounds().contains(mousePosition.x,mousePosition.y)) return 1;
	else if(next.getGlobalBounds().contains(mousePosition.x,mousePosition.y))skinNumber++;
	else if(previous.getGlobalBounds().contains(mousePosition.x,mousePosition.y))skinNumber--;
	changeSkin();
}
void Shop::changeSkin() {
	if (skinNumber < 0)skinNumber = 2;
	else if (skinNumber > 2)skinNumber = 0;
	skinPath = "./resources/";
	switch (skinNumber) {
	case 0: {
		skinPath += "first";
		break;
	}
	case 1: {
		skinPath += "second";
		break;
	}
	case 2: {
		skinPath += "third";
		break;
	}
	default:{
		skinPath += "first";
		break;
	}
		  break; 
	}
	resManager.LoadTexture("TimbermanIdle",skinPath+"SkinIdle.png");
	resManager.LoadTexture("TimbermanChop",skinPath+"SkinChop.png");
	return;
}
