#include "Classes.h"
Menu::Menu(sf::Vector2f size):Object(size){

}
void Menu::Draw(sf::RenderWindow& window)
{
	start = sf::RectangleShape(sf::Vector2f(size.x / 2.f, size.y / 10.f));
	exit = sf::RectangleShape(sf::Vector2f(size.x / 2.f, size.y / 10.f));

	start.setFillColor(sf::Color::Blue);
	exit.setFillColor(sf::Color::Red);

	start.setPosition(size.x /2.f-(size.x/4.f), size.y *(1/5.f));
	exit.setPosition(size.x / 2.f-(size.x/4.f), size.y * (2/5.f));
	window.clear();
	window.draw(start);
	window.draw(exit);
	window.display();
}
int Menu::OnClick(sf::Vector2i mousePosition)
{
	if (start.getGlobalBounds().contains(mousePosition.x,mousePosition.y)) return 1;
	else if (exit.getGlobalBounds().contains(mousePosition.x,mousePosition.y)) return 2;
}
