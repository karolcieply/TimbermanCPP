#include <SFML/Graphics.hpp>
#include<iostream>
#include "Definitions.h"
#include <windows.h>
#include <winbase.h>
#include<fstream>
#include <SFML/Audio.hpp>
//static unsigned short int windowWidth{ 540 }, windowHeight{ 960 };
//to trzeba ogarnąć bo nie wiadomo czemu nie działają globalne?
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
		//przyciski menu
		sf::RectangleShape start;
		sf::RectangleShape exit;
		sf::RectangleShape topScores;
		sf::RectangleShape rules;
		sf::RectangleShape shop;
	public:
		bool LoadTextures();
		Menu();
		virtual ~Menu() = default;
		//rysowanie menu 
		void Draw(sf::RenderWindow& window);
		//sprawdzanie czy i który przycisk kliknięty 
		int OnClick(sf::Vector2i);
};
class Player : public Object {
	private:
		sf::Clock clock;
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
		friend bool checkColission(Player* p, Tree* t);
		bool LoadTexture();
	
};
class Tree: public Object{
	private:
		unsigned short int branchPosition; //0-lewo 1-nie ma 2-prawo
		sf::RectangleShape log;
	public:
		Tree() {};
		Tree(int branchPosition);
		virtual ~Tree() { std::cout << "dziala"; };
		//funkcja zaprzyjaźniona z graczem sprawdzająca czy gałąź dotyka gracza
		friend bool checkColission(Player* p, Tree* t);
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
	Tree* treeArray[6]{};
	Player playerObj{};
	sf::Text text{};
	sf::Clock timePassed{};
	sf::RectangleShape timerRectangle{};
	sf::Sprite timerBorder{};
	bool isPaused=true;
	sf::Time maxTime =sf::microseconds(15000000);
	sf::Music testSound;
public:
	void Draw(sf::RenderWindow& window);
	Game();
	virtual ~Game()=default;
	//funkcja bedzie zwracala ilosc punktow
	//funkcja wywolywana przy kazdej kluczowej klatce gry
	void GameFrame(sf::Keyboard::Key);
	bool CheckTextures();
	unsigned int GetScore() { return this->score; };
	bool IsGameOver();
};
class ResourcesManager {
public:
	ResourcesManager() { }
	~ResourcesManager() { }

	void LoadTexture(std::string name, std::string file);
	sf::Texture& GetTexture(std::string name);

	void LoadFont(std::string name, std::string file);
	sf::Font& GetFont(std::string name);
	void UpdateArray(unsigned int );
	void LoadTopScores();
	void SaveTopScores();
	std::string GetTime();
	unsigned int GetTopScore();
	std::string GetWholeScore(int which);


private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	SYSTEMTIME st;
	std::string topScores[30];
	std::ifstream inputFile;
	std::ofstream outputFile;
	
};
extern ResourcesManager resManager;
class Pause :public Object{
	private:
		//przyciski menu
		sf::RectangleShape resume;
		sf::RectangleShape backToMenu;
		sf::RectangleShape pauseScreen{};
	public:
		bool LoadTextures();
		Pause();
		virtual ~Pause() = default;
		//rysowanie menu 
		void Draw(sf::RenderWindow& window);
		//sprawdzanie czy i który przycisk kliknięty 
		int OnClick(sf::Vector2i);
};
class GameOver
{
private:
	sf::RectangleShape gameOverScreen{};
	sf::Text endingScore{};
	sf::Text bestScore{};
	std::string scoreString{};
	std::string bestScoreString{};
	sf::RectangleShape backMenu{};
	sf::RectangleShape playAgain{};
public:
	GameOver(unsigned int score);
	virtual ~GameOver() = default;
	void Draw(sf::RenderWindow& window);
	int OnClick(sf::Vector2i);
};
class HighScores :public Object
{
	private:
		sf::RectangleShape backToMenu{};
		sf::RectangleShape highScoreScreen{};
		sf::Text hsText{};

	public:
		HighScores();
		virtual ~HighScores() = default;
		void Draw(sf::RenderWindow& window);
		int OnClick(sf::Vector2i);
};
class Rules :public Object
{
	private:
		sf::RectangleShape backToMenu{};
		sf::RectangleShape rulesScreen{};
	public:
		Rules();
		virtual ~Rules() = default;
		void Draw(sf::RenderWindow& window);
		int OnClick(sf::Vector2i);
};
class Shop :public Object
{
	private:
		short skinNumber{};
		sf::RectangleShape backToMenu{};
		sf::RectangleShape previous{};
		sf::RectangleShape next{};
		sf::RectangleShape shopScreen{};
		sf::Clock clock{};
		sf::RectangleShape chosenSkin{};
		std::string skinPath{};
		void changeSkin();
	public:

		Shop();
		virtual ~Shop() = default;
		void Draw(sf::RenderWindow& window);
		int OnClick(sf::Vector2i);
};

