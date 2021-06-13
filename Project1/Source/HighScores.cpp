#include "Classes.h"
HighScores::HighScores()
{
	highScoreScreen.setSize(sf::Vector2f(windowWidth/1.5f, windowHeight/1.25f));
	highScoreScreen.setFillColor(sf::Color::White);
	highScoreScreen.setOrigin(sf::Vector2f(highScoreScreen.getSize().x/2.f, highScoreScreen.getSize().y/2.f));
	highScoreScreen.setPosition(sf::Vector2f(windowWidth/2.F , windowHeight/2.F));
	highScoreScreen.setTexture(&resManager.GetTexture("highScoreBackground"));

	backToMenu = sf::RectangleShape(sf::Vector2f(windowWidth/ 2.f, windowHeight / 10.f));
	backToMenu.setPosition(windowWidth/2.f-(windowWidth/4.f), windowHeight *(3.5/5.f));
	backToMenu.setTexture(&resManager.GetTexture("menuButton"));

	hsText.setFont(resManager.GetFont("font"));
	hsText.setCharacterSize(18);
	hsText.setFillColor(sf::Color::Black);
}
void HighScores::Draw(sf::RenderWindow& window)
{
	window.draw(highScoreScreen);
	window.draw(backToMenu);
	for (int i = 0; i<10; i++) {
		std::cout << resManager.GetWholeScore(i)<<"\n";
		hsText.setString(resManager.GetWholeScore(i));
		hsText.setPosition(windowWidth/2.f-windowWidth/4.f,windowHeight/5.f+i*windowHeight/20.f);
		window.draw(hsText);
	}
}
int HighScores::OnClick(sf::Vector2i mousePosition)
{
	if (backToMenu.getGlobalBounds().contains(mousePosition.x,mousePosition.y)) return 1;
}