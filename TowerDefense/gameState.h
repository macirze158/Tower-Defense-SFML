#pragma once
#include "libIncludes.h"

class GameState
{
private:
	int money;
	int score;
	short int healthPoints;
	sf::Font font;
	sf::Text data;
	sf::Text gameOver;
	bool gameIsOver;
public:
	GameState(std::string fontPath, int charSize, int money, int score, unsigned short int HP);
	void setMoney(int newMoney);
	void setHealtPoints(short int newHP);
	void setScore(int newScore);
	int getMoney();
	short int getHealthPoints();
	int getScore();
	sf::Text getData();
	void updateData();
	bool isGameOver();
	void drawGameOver(sf::RenderWindow& window);
};