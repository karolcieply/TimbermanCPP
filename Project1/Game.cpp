#include "Classes.h"
 bool checkColission(Player p, Tree t) {
	 if (p.isRight && t.branchPosition == 2)return true;
	else if (!p.isRight && t.branchPosition == 0)return true;	
	 return false;
}
Game::Game() {

	for (int i = 0; i < 6; i++) {
		treeArray[i] = Tree(1);
		treeArray[i].MoveDown(5-i);
	}
	CheckTextures();
}
 bool Game::CheckTextures() {
	for(auto& t : treeArray){
		if(!t.LoadTextures())return false;
	}
	playerObj.LoadTexture();
	font.loadFromFile("./resources/font.ttf");
	return true;
 }
void Game::Draw(sf::RenderWindow& window)
{
	window.clear();
	for(auto& t : treeArray){
		t.Draw(window);
	}
	playerObj.Draw(window);
	text.setFont(font);

	text.setString(std::to_string(score));

	window.draw(text);
	window.display();
}
unsigned int Game::GameFrame(sf::Keyboard::Key pressedKey) {
	if (pressedKey != 72 && pressedKey != 71) return 1;
	if(pressedKey==sf::Keyboard::Key::Right)
	{
		playerObj.setRight(true);
	}
	else if(pressedKey==sf::Keyboard::Key::Left)
	{
		playerObj.setRight(false);
	}
		for (int i = 0; i < 6; i++)
		{
			treeArray[i].MoveDown(1);
		}
		std::cout << score;
		if (checkColission(playerObj, treeArray[(score+1) % 6]))return score;
		treeArray[score % 6].MoveDown(-6);
		treeArray[score % 6].RollBranch();
		score++;
		return 0;
}
