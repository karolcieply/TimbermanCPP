#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "./Source/Definitions.h"
#include "./Source/Classes.h"
//wczytanie wszystkich zasobów
void LoadResources() {
		resManager.LoadTopScores();
		resManager.LoadFont("font", FONT_FILE);
		resManager.LoadTexture("background", BACKGROUND_FILE);
		resManager.LoadTexture("TimbermanIdle", TIMBERMAN_IDLE_SPRITE);
		resManager.LoadTexture("TimbermanChop", TIMBERMAN_CHOP_SPRITE);
		resManager.LoadTexture("TreeLeft", TREE_LEFT_TEXTURE);
		resManager.LoadTexture("Tree", TREE_NEUTRAL_TEXTURE);
		resManager.LoadTexture("TreeRight", TREE_RIGHT_TEXTURE);
		resManager.LoadTexture("start", START_TEXTURE);
		resManager.LoadTexture("exit", EXIT_TEXTURE);
		resManager.LoadTexture("timerBorder", TIMER_BORDER_TEXTURE);
		resManager.LoadTexture("GameOver", GAME_OVER_TEXTURE);
		resManager.LoadTexture("highScore", HIGH_SCORES_BUTTON);
		resManager.LoadTexture("highScoreBackground", HIGH_SCORES_BACKGROUND);
		resManager.LoadTexture("menuButton", MAIN_MENU_BUTTON);
		resManager.LoadTexture("playAgainButton", PLAY_AGAIN_BUTTON);
		resManager.LoadTexture("rulesButton", RULES_BUTTON);
		resManager.LoadTexture("rulesBackground", RULES_BACKGROUND);
		resManager.LoadTexture("smallExitButton", SMALL_EXIT_BUTTON);
		resManager.LoadTexture("shopButton", SHOP_BUTTON);
		resManager.LoadTexture("arrowButton", ARROW_BUTTON);
		resManager.LoadTexture("pauseBackground",PAUSE_BACKGROUND);
		resManager.LoadTexture("continueButton",CONTINUE_BUTTON);
}
int main()
{
	enum STATES {
		MENU, GAME, GAMEOVER, PAUSE, HIGHSCORES, RULES, SHOP
	};
	char GAME_STATE = STATES::MENU;
	unsigned int score{};
	//tworzenie okna 
	sf::RenderWindow window{ sf::VideoMode(windowWidth,windowHeight),"\"Timberman\"" };
	window.setFramerateLimit(frameLimit);
	window.setKeyRepeatEnabled(false);
	//tworzenie wskaŸników kluczowych obiektow 
	Game* gameObj{};
	Menu* menuObj{};
	Pause* pauseObj{};
	GameOver* gameOverObj{};
	HighScores* highScoresObj{};
	Shop* shopObj{};
	Rules* rulesObj{};
	//wywo³anie funkcji wczytuj¹cej zasoby i stworzenie t³a
	LoadResources();
	sf::Sprite background;
	background.setTexture(resManager.GetTexture("background"));
	window.draw(background);
	//wczytywanie dŸwiêku
	sf::Sound buttonClick;
	static sf::SoundBuffer buttonSoundBuffer;
	buttonSoundBuffer.loadFromFile(BUTTON_CLICK_SOUND);
	buttonClick.setBuffer(buttonSoundBuffer);
	sf::Music backgroundMusic;
	backgroundMusic.openFromFile(BACKGROUND_MUSIC);
	backgroundMusic.setLoop(true);
	backgroundMusic.setVolume(10.f);
	backgroundMusic.play();

	while (window.isOpen()) {
		sf::Event event;
		switch (GAME_STATE) {
		case MENU:
		{
			if (menuObj == NULL)
				menuObj = new Menu();
			window.clear();
			window.draw(background);
			menuObj->Draw(window);
			window.display();
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					switch (menuObj->OnClick(sf::Mouse::getPosition(window))) {
					case 1: {
						buttonClick.play();
						delete menuObj;
						menuObj = NULL;
						GAME_STATE = STATES::GAME;
						break;
					}
					case 2: {
						buttonClick.play();
						Sleep(100);
						window.close();
						break;
					}
					case 3: {
						buttonClick.play();
						delete menuObj;
						menuObj = NULL;
						GAME_STATE = STATES::HIGHSCORES;
						break;
					}
					case 4: {
						buttonClick.play();
						delete menuObj;
						menuObj = NULL;
						GAME_STATE = STATES::RULES;
						break;
					}
					case 5: {
						buttonClick.play();
						delete menuObj;
						menuObj = NULL;
						GAME_STATE = STATES::SHOP;
						break;
					}
					}
				}
				break;
				//bez tego break'a wyrzuca program w losowych momentach?
			}
			break;
		}
		case GAME:
		{
			if (gameObj == NULL)
				gameObj = new Game();
			window.clear();
			window.draw(background);
			gameObj->Draw(window);
			window.display();
			if (gameObj->IsGameOver()) {
				score = gameObj->GetScore();
				delete gameObj;
				gameObj = NULL;
				GAME_STATE = STATES::GAMEOVER;
				break;
			};
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					break;
				}
				if (event.type == sf::Event::KeyPressed) {
					gameObj->GameFrame(event.key.code);
					if (event.key.code == sf::Keyboard::Escape) {
						GAME_STATE = STATES::PAUSE;
						break;
					}
				}
				break;
			}
			break;
		}
		case GAMEOVER: {
			if (gameOverObj == NULL)
				gameOverObj = new GameOver(score);
			window.clear();
			window.draw(background);
			gameOverObj->Draw(window);
			window.display();
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					break;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					switch (gameOverObj->OnClick(sf::Mouse::getPosition(window))) {
					case 1: {
						buttonClick.play();
						delete gameOverObj;
						gameOverObj = NULL;
						GAME_STATE = STATES::GAME;
						break;
					}
					case 2: {
						buttonClick.play();
						delete gameOverObj;
						gameOverObj = NULL;
						GAME_STATE = STATES::MENU;
						break;
					}
					}
				}
				break;
			}
			break;
		}
		case PAUSE:
		{
			if (pauseObj == NULL)
				pauseObj = new Pause();

			pauseObj->Draw(window);
			window.display();
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					break;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					switch (pauseObj->OnClick(sf::Mouse::getPosition(window))) {
					case 1:
					{
						buttonClick.play();
						delete pauseObj;
						pauseObj = NULL;
						GAME_STATE = STATES::GAME;
						break;

					}
					case 2:
					{
						buttonClick.play();
						delete pauseObj;
						pauseObj = NULL;
						delete gameObj;
						gameObj = NULL;
						GAME_STATE = STATES::MENU;
						break;
					}
					}
				}
				break;
			}
			break;
		}
		case HIGHSCORES:
		{
			if (highScoresObj == NULL)
				highScoresObj = new HighScores();
			window.clear();
			window.draw(background);
			highScoresObj->Draw(window);
			window.display();
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					break;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (highScoresObj->OnClick(sf::Mouse::getPosition(window)) == 1)
					{
						buttonClick.play();
						delete highScoresObj;
						highScoresObj = NULL;
						//delete gameObj;
						//gameObj = NULL;
						GAME_STATE = STATES::MENU;
						break;
					}
				}
			}
			break;
		}
		case RULES:
		{
			if (rulesObj == NULL)
				rulesObj = new Rules();
			window.clear();
			window.draw(background);
			rulesObj->Draw(window);
			window.display();
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					break;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (rulesObj->OnClick(sf::Mouse::getPosition(window)) == 1)
					{
						buttonClick.play();
						delete rulesObj;
						rulesObj = NULL;
						GAME_STATE = STATES::MENU;
						break;
					}
				}
				break;
			}
			break;
		}
		case SHOP:
		{
			if (shopObj == NULL)
				shopObj = new Shop();
			window.clear();
			window.draw(background);
			shopObj->Draw(window);
			window.display();
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					break;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (shopObj->OnClick(sf::Mouse::getPosition(window)) == 1)
					{
						buttonClick.play();
						delete shopObj;
						shopObj = NULL;
						GAME_STATE = STATES::MENU;
						break;
					}
				}
				break;
			}
			break;
		}
		break;
		}
	}
	resManager.SaveTopScores();
	return 0;
}
