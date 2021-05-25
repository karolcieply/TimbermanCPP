#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Classes.h"
int main()
{
	//deklaracja kluczowych zmiennych
	static unsigned short int windowWidth{ 540 }, windowHeight{ 960 }, frameLimit{ 60 };
	//deklaracja stanow gry
	enum STATES {
		MENU, GAME, GAMEOVER
	};
	char GAME_STATE = STATES::MENU;
	unsigned int score{};

	//tworzenie okna 
	sf::RenderWindow window{ sf::VideoMode(windowWidth,windowHeight),"\"Timberman\"" };
	window.setFramerateLimit(frameLimit);
	window.setKeyRepeatEnabled(false);
	//tworzenie kluczowych obiektow 
	Menu menu(sf::Vector2f(windowWidth, windowHeight));
	Game* gameObj{};
	sf::Sprite background;
	sf::Texture backgroundTextutre;
	backgroundTextutre.loadFromFile("./resources/tlo.png");
	background.setTexture(backgroundTextutre);
	window.draw(background);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
			switch (GAME_STATE) {
			case MENU:
			{
				window.clear();
				window.draw(background);
				menu.Draw(window);
				window.display();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					switch (menu.OnClick(sf::Mouse::getPosition(window))) {
					case 1: {
						gameObj = new Game();
						GAME_STATE = STATES::GAME;
						break;
					}
					case 2:
						window.close();
						break;
					}
				}
				break;
			}
			case GAME:
			{
				window.clear();
				window.draw(background);
				gameObj->Draw(window);
				window.display();
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						window.close();
					}
					if (event.type == sf::Event::KeyPressed) {
						if (gameObj->GameFrame(event.key.code) != 0) {
							score = gameObj->GetScore();
							delete gameObj;
							GAME_STATE = STATES::MENU;
						}
						if (event.key.code == sf::Keyboard::Escape) {
							score = gameObj->GetScore();
							delete gameObj;
							GAME_STATE = STATES::MENU;
						}
						break;
					}
				}
			}
			case GAMEOVER: {
				//std::cout << "You lost, score=:" << score;
				break;
			}
			}
		}
	return 0;
	}
