#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <queue>
#include "Classes.h"
bool checkColission(Player p, Tree t) {
	if (p.isRight && t.branchPosition == 2)return true;	
	else if (!p.isRight && t.branchPosition == 0)return true;	
}
int main()
{

	static unsigned short int windowWidth{ 540 }, windowHeight{ 960 }, frameLimit{ 60 };
	//deklaracja kluczowych zmiennych
	enum STATES {
		MENU, GAME
	};
	char GAME_STATE = STATES::MENU;

	//tworzenie okna 
	sf::RenderWindow window{ sf::VideoMode(windowWidth,windowHeight),"\"Timberman\"" };
	window.setFramerateLimit(frameLimit);
	Menu menu(sf::Vector2f(windowWidth,windowHeight));
	Player playerObj;
	//Tree * TreeArray=new Tree[7];
	Tree TreeArray[6];
	for (int i = 0; i < 6; i++) {
		TreeArray[i] = Tree(1);
		TreeArray[i].MoveDown(5 - i);
	}
	
	while (window.isOpen()) {
		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		switch (GAME_STATE) {
		case MENU:
			menu.Draw(window);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				switch (menu.OnClick(sf::Mouse::getPosition(window))) {
				case 1:
					GAME_STATE = STATES::GAME;
					break;
				case 2:
					window.close();
					break;
				}
			}
		break;
		case GAME:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
				playerObj.setRight(true);
				window.clear();
				playerObj.Draw(window);
				for (int i = 0; i < 6; i++) {
					TreeArray[i].Draw(window);
				}
				window.display();
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
				playerObj.setRight(false);
				window.clear();
				playerObj.Draw(window);
				for (int i = 0; i < 6; i++) {
					TreeArray[i].Draw(window);
				}
				window.display();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
				GAME_STATE = STATES::MENU;
			}
		break;
		}
	}
	return 0;
}
