#include <SFML/Graphics.hpp>
#include<iostream>
//to trzeba ogarnąć bo nie wiadomo czemu nie działają globalne?
static unsigned short int windowWidth{ 540 }, windowHeight{ 960 };
class Tree;
//klasa bazowa na ktorej bazuja inne klasy
class Object {
private:
	sf::Vector2f position;
	sf::Vector2f size;
public:
	virtual ~Object()=default;
	//gettery i settery
	void SetSize(sf::Vector2f size) { this->size = size; };
	sf::Vector2f GetSize() { return size; };
	void SetPosition(sf::Vector2f position) { this->position = position; };
	sf::Vector2f GetPosition() { return position; };
	//konstruktory
	Object();
	Object(sf::Vector2f size ,sf::Vector2f position);
};
class Menu :public Object{
	private:
		sf::Texture startTexture;
		sf::Texture exitTexture;
        sf::Font font;
		//przyciski menu
		sf::RectangleShape start;
		sf::RectangleShape exit;
	public:
		bool LoadTextures();
		Menu(sf::Vector2f size);
		virtual ~Menu() = default;
		//rysowanie menu 
		void Draw(sf::RenderWindow& window);
		//sprawdzanie czy i który przycisk kliknięty 
		int OnClick(sf::Vector2i);
};
class Player : public Object {
	private:
		sf::Clock clock;
		sf::Texture texture;
		sf::Texture textureIdle;
		sf::RectangleShape playerShape;
		//sf::Texture textureRight;
		unsigned int score{};
		bool isGame{},isRight=0;
	public:
		Player();
		virtual ~Player() = default;
		//rysowanie gracza
		void Draw(sf::RenderWindow& window);
		//ustawianie pozycji gracza
		void setRight(bool isRight);
		//funkcja zaprzyjaźniona z drzewem sprawdzająca czy gracz dotknął gałęzi 
		friend bool checkColission(Player p, Tree t);
		bool LoadTexture();
	
};
class Tree: public Object{
	private:
		unsigned short int branchPosition; //0-lewo 1-nie ma 2-prawo
		sf::RectangleShape log;
		sf::Texture treeTextureLeft;
		sf::Texture treeTexture;
		sf::Texture treeTextureRight;
		
	public:
		Tree() {};
		Tree(int branchPosition);
		virtual ~Tree() = default;
		//funkcja zaprzyjaźniona z graczem sprawdzająca czy gałąź dotyka gracza
		friend bool checkColission(Player p, Tree t);
		//przesuwanie galezi w dol na ekrani
		void MoveDown(int multiplier);
		//rysowanie galezi
		void Draw(sf::RenderWindow& window);
		bool LoadTextures();
		void RollBranch();
};
class Game
{
	private:
		unsigned int score{};
		//time;
		//wywolane obiekty porzebne do gry
		Tree treeArray[6];
		Player playerObj;
		sf::Font font;
		sf::Text text;
		

	public:
		void Draw(sf::RenderWindow& window);
		Game();
		virtual ~Game() { std::cout << this->score; };
		//funkcja bedzie zwracala ilosc punktow
		//funkcja wywolywana przy kazdej kluczowej klatce gry
		unsigned int GameFrame(sf::Keyboard::Key);
		bool CheckTextures();
		unsigned int GetScore() { return this->score; };

};