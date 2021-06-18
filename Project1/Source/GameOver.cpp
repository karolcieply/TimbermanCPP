#include "Classes.h"
GameOver::GameOver(unsigned int score)
{
		resManager.UpdateArray(score);

		gameOverScreen.setSize(sf::Vector2f(windowWidth/1.5f, windowHeight/1.25f));
		gameOverScreen.setFillColor(sf::Color::White);
		gameOverScreen.setOrigin(sf::Vector2f(gameOverScreen.getSize().x/2.f, gameOverScreen.getSize().y/2.f));
		gameOverScreen.setPosition(sf::Vector2f(windowWidth/2.F , windowHeight/2.F));
		gameOverScreen.setTexture(&resManager.GetTexture("GameOver"));
		backMenu.setSize(sf::Vector2f(windowWidth/ 2.f, windowHeight / 10.f));
		//backMenu.setOrigin(sf::Vector2f(backMenu.getSize().x/2.f, backMenu.getSize().y/2.f));
		backMenu.setPosition(sf::Vector2f(windowWidth /2.f-(windowWidth/4.f), windowHeight*(4.5/6.f)));
		backMenu.setTexture(&resManager.GetTexture("menuButton"));
		playAgain.setSize(sf::Vector2f(windowWidth/ 2.f, windowHeight / 10.f));
		//playAgain.setOrigin(sf::Vector2f(playAgain.getSize().x/2.f, playAgain.getSize().y/2.f));
		playAgain.setPosition(sf::Vector2f(windowWidth /2.f-(windowWidth/4.f), windowHeight*(3.5/6.f)));
		playAgain.setTexture(&resManager.GetTexture("playAgainButton"));

		//font.loadFromFile(FONT_FILE);

		scoreString = "SCORE ";
		scoreString +=std::to_string(score);
		bestScoreString = "BEST ";
		bestScoreString +=std::to_string(resManager.GetTopScore());

		endingScore.setString(scoreString);
		endingScore.setFont(resManager.GetFont("font"));
		endingScore.setPosition(sf::Vector2f(windowWidth/3,windowHeight/3));
		endingScore.setFillColor(sf::Color::Black);

		bestScore.setString(bestScoreString);
		bestScore.setFont(resManager.GetFont("font"));
		bestScore.setPosition(sf::Vector2f(windowWidth/3,windowHeight/3+windowHeight/7));
		bestScore.setFillColor(sf::Color::Black);
		if (score < resManager.GetTopScore())
			gameEndingSoundBuffer.loadFromFile(GAME_OVER_SOUND);
		else
			gameEndingSoundBuffer.loadFromFile(NEW_BEST_SCORE_SOUND);
		gameEndingSound.setBuffer(gameEndingSoundBuffer);
		gameEndingSound.play();
}
void GameOver::Draw(sf::RenderWindow& window)
{
	window.draw(gameOverScreen);
	window.draw(endingScore);
	window.draw(bestScore);
	window.draw(backMenu);
	window.draw(playAgain);
}
int GameOver::OnClick(sf::Vector2i mousePosition)
{
	if (playAgain.getGlobalBounds().contains(mousePosition.x,mousePosition.y)) return 1;
	else if (backMenu.getGlobalBounds().contains(mousePosition.x,mousePosition.y)) return 2;
}
