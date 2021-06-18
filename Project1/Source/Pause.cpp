#include "Classes.h"
Pause::Pause():Object(sf::Vector2f(windowWidth,windowHeight),sf::Vector2f(0,0)){
		pauseScreen.setSize(sf::Vector2f(windowWidth/1.5f, windowHeight/1.25f));
		pauseScreen.setFillColor(sf::Color::White);
		pauseScreen.setOrigin(sf::Vector2f(pauseScreen.getSize().x/2.f, pauseScreen.getSize().y/2.f));
		pauseScreen.setPosition(sf::Vector2f(windowWidth/2.F , windowHeight/2.F));
		pauseScreen.setTexture(&resManager.GetTexture("highScoreBackground"));
		backToMenu.setSize(sf::Vector2f(windowWidth/ 2.f, windowHeight / 10.f));
		backToMenu.setPosition(sf::Vector2f(windowWidth /2.f-(windowWidth/4.f), windowHeight*(4.5/6.f)));
		backToMenu.setTexture(&resManager.GetTexture("menuButton"));
		resume.setSize(sf::Vector2f(windowWidth/ 2.f, windowHeight / 10.f));
		resume.setPosition(sf::Vector2f(windowWidth /2.f-(windowWidth/4.f), windowHeight*(3.5/6.f)));
		resume.setTexture(&resManager.GetTexture("playAgainButton"));

		//font.loadFromFile(FONT_FILE);

}
void Pause::Draw(sf::RenderWindow& window)
{
	window.draw(pauseScreen);
	window.draw(resume);
	window.draw(backToMenu);
}
int Pause::OnClick(sf::Vector2i mousePosition)
{
	if (resume.getGlobalBounds().contains(mousePosition.x,mousePosition.y)) return 1;
	else if (backToMenu.getGlobalBounds().contains(mousePosition.x,mousePosition.y)) return 2;
}
