#include "Classes.h"
Menu::Menu(sf::Vector2f size):Object(size,sf::Vector2f(0,0)){

	start = sf::RectangleShape(sf::Vector2f(GetSize().x / 2.f, GetSize().y / 10.f));
	exit = sf::RectangleShape(sf::Vector2f(GetSize().x / 2.f, GetSize().y / 10.f));

	start.setFillColor(sf::Color::Blue);
	exit.setFillColor(sf::Color::Red);

	start.setPosition(GetSize().x /2.f-(GetSize().x/4.f), GetSize().y *(1/5.f));
	exit.setPosition(GetSize().x / 2.f-(GetSize().x/4.f), GetSize().y * (2/5.f));

}
void Menu::Draw(sf::RenderWindow& window)
{
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
