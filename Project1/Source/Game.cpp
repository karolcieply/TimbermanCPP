#include "Classes.h"
 bool checkColission(Player* p, Tree*t) {
	 if (p->isRight && t->branchPosition == 2)return true;
	else if (!p->isRight && t->branchPosition == 0)return true;	
	 return false;
}
Game::Game() {
	for (int i = 0; i < 6; i++) {
		*(treeArray+i) = new Tree(1);
		treeArray[i]->MoveDown(5-i);
	}
	timerRectangle.setFillColor(sf::Color::Red);
	timerRectangle.setSize(sf::Vector2f(windowWidth/3.F, windowHeight / 20.f));
	timerRectangle.setPosition(sf::Vector2f(windowWidth/2.f-timerRectangle.getSize().x/2.f, windowHeight / 7.f));
	text.setFont(resManager.GetFont("font"));
	timerBorder.setTexture(resManager.GetTexture("timerBorder"));
	timerBorder.setPosition(timerRectangle.getPosition()-sf::Vector2f(10,10));
	chopSoundBuffer.loadFromFile(TREE_CHOP_SOUND);
	chopSound.setBuffer(chopSoundBuffer);
}
void Game::Draw(sf::RenderWindow& window)
{
	for(auto& t : treeArray){
		t->Draw(window);
	}
	playerObj.Draw(window);
	window.draw(timerBorder);
	if (!isPaused)
		timerRectangle.setScale((maxTime.asSeconds() - timePassed.getElapsedTime().asSeconds()) / maxTime.asSeconds(), 1);
	else
		timerRectangle.setScale(1, 1);
	window.draw(timerRectangle);
	text.setString(std::to_string(score));
	window.draw(text);
}
bool Game::IsGameOver() {
	if (checkColission(&playerObj, treeArray[score % 6]))return true;
	else if (!isPaused && timePassed.getElapsedTime().asMicroseconds()>maxTime.asMicroseconds()) return true;
	return false;
}
void Game::GameFrame(sf::Keyboard::Key pressedKey) {
	if (pressedKey == sf::Keyboard::Escape) {
		maxTime =sf::microseconds( maxTime.asMicroseconds()- timePassed.getElapsedTime().asMicroseconds());
		isPaused = true;
		return;
	}	
	if (pressedKey == 72 || pressedKey == 71) {
		chopSound.play();
		if (isPaused) {
			timePassed.restart();
			isPaused = false;
		}
		if (pressedKey == sf::Keyboard::Key::Right)
		{
			playerObj.setRight(true);
		}
		else if (pressedKey == sf::Keyboard::Key::Left)
		{
			playerObj.setRight(false);
		}
		isPaused = false;
		for (int i = 0; i < 6; i++)
		{
			treeArray[i]->MoveDown(1);
		}
		treeArray[score % 6]->MoveDown(-6);
		treeArray[score % 6]->RollBranch();
		score++;
		maxTime = sf::seconds(maxTime.asSeconds()+ 2/sqrt(score));
		return;
	}
	return;
}
