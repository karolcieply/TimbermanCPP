#include <SFML/Graphics.hpp>
#include<iostream>
//klasa bazowa na której bazuj¹ inne klasy
static unsigned short int windowWidth{ 540 }, windowHeight{ 960 };
class Tree;
class Object {
public:
	Object();
	Object(sf::Vector2f size);
	Object(sf::Vector2f size ,sf::Vector2f position);
	sf::Vector2f position;
	sf::Vector2f size;
private:
};
class Menu :public Object{
	private:
        sf::Font font;
		sf::RectangleShape start;
		sf::RectangleShape exit;
	public:
		Menu(sf::Vector2f size);
		~Menu() = default;
		void Draw(sf::RenderWindow& window);
		int OnClick(sf::Vector2i);
};
class Player : public Object {
	private:
		sf::Texture texture;
		unsigned int score{};
		bool isGame{},isRight=1;
		public:
		Player();
		~Player() = default;
		void Draw(sf::RenderWindow& window);
		void setRight(bool isRight);
		friend bool checkColission(Player p, Tree t);
	
};
class Tree: public Object{
	private:
		unsigned short int branchPosition; //0-lewo 1-nie ma 2-prawo
		sf::Vector2f position;
		sf::RectangleShape log;
	public:
		Tree();
		Tree(int branchPosition);
		~Tree() = default;
		friend bool checkColission(Player p, Tree t);
		void MoveDown(int multiplier);
		void Draw(sf::RenderWindow& window);
};