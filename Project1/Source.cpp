#include "Classes.h"
#include <SFML/Graphics.hpp>
int PositionToPixels(int x) {
	switch (x)
	{
	case 0:
		return 195;
	case 1:
		return 295;
	}
}
int main()
{
	Timberman Player;
	sf::RectangleShape rectangle(sf::Vector2f(50, 50));
	rectangle.setFillColor(sf::Color::White);
	sf::RenderWindow window(sf::VideoMode(540,960), "Nauka");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		window.draw(rectangle);
		window.display();
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Left) {
				Player.ChangePosition(Timberman::positionEnum::left);
			}
			if (event.key.code == sf::Keyboard::Right) {
				Player.ChangePosition(Timberman::positionEnum::right);
			}
		}
		rectangle.setPosition(PositionToPixels(Player.playerPosition),910);
		}
	return 0;
}
