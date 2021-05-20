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
		MENU, GAME
	};
	char GAME_STATE = STATES::MENU;

	//tworzenie okna 
	sf::RenderWindow window{ sf::VideoMode(windowWidth,windowHeight),"\"Timberman\"" };
	window.setFramerateLimit(frameLimit);
	window.setKeyRepeatEnabled(false);
	//tworzenie kluczowych obiektow 
	Menu menu(sf::Vector2f(windowWidth, windowHeight));
	Game gameObj;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			switch (GAME_STATE) {
			case MENU:
				menu.Draw(window);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					switch (menu.OnClick(sf::Mouse::getPosition(window))) {
					case 1: {
						GAME_STATE = STATES::GAME;
						break;
					}
					case 2:
						window.close();
						break;
					}
				}
				break;
			case GAME:
				gameObj.Draw(window);
				if (event.type == sf::Event::KeyPressed) {
					if(gameObj.GameFrame(event.key.code) != 0){
						window.close();
						std::cout << "przegrales";
						return 0;
					}
					if (event.key.code == sf::Keyboard::Escape) {
						GAME_STATE = STATES::MENU;
					}
			default:
				break;
				}
			}
		}
	}
	return 0;
}
