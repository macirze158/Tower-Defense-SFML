#include "gameState.h"

GameState::GameState(std::string fontPath, int charSize, int money, int score, unsigned short int HP)
{
	this->money = money;
	this->score = score;
	this->healthPoints = HP;
	font.loadFromFile(fontPath);
	data.setCharacterSize(charSize);
	data.setFillColor(sf::Color::White);
	data.setFont(font);
	data.setOutlineThickness(2);
	data.setString("Lives:"+ std::to_string(this->healthPoints) + "\nMoney: " + std::to_string(this->money) + "\nScore: " + std::to_string(this->score));
	data.setPosition(0, 600);
}

void GameState::setMoney(int newMoney)
{
	if (isGameOver() == false)
		this->money = newMoney;
	else
		this->money = 0;
}
void GameState::setHealtPoints(short int newHP)
{
	this->healthPoints = newHP;
}
void GameState::setScore(int newScore)
{
	if (isGameOver() == false)
		this->score = newScore;
}
int GameState::getMoney()
{
	return this->money;
}
short int GameState::getHealthPoints()
{
	return this->healthPoints;
}
int GameState::getScore()
{
	return this->score;
}

sf::Text GameState::getData()
{
	return this->data;
}

void GameState::updateData()
{
	data.setString("Lives: " + std::to_string(this->healthPoints) + "\nMoney: " + std::to_string(this->money) + "\nScore: " + std::to_string(this->score));
}

bool GameState::isGameOver()
{
	return this->healthPoints <= 0;
}

void GameState::drawGameOver(sf::RenderWindow& window)
{
	if (this->healthPoints <= 0)
	{
		gameOver.setCharacterSize(100);
		gameOver.setFillColor(sf::Color::Red);
		gameOver.setFont(font);
		gameOver.setOutlineThickness(2);
		gameOver.setString("GAME OVER");
		gameOver.setOrigin(gameOver.getLocalBounds().width/2, gameOver.getLocalBounds().height/2);
		gameOver.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		window.draw(gameOver);
	}
}