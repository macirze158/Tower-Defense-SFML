#pragma once
#include "libIncludes.h"
#include "enemy.h"
#include "tileSet.h"

class EnemyGenerator
{
private:
	float RELEASE_SPEED_UP = 0.95f; //const

	sf::Vector2i position;
	float releaseTime = 3.0f;
	sf::Clock releaseTimer;
	std::vector<Enemy> enemies;
	sf::Texture enemyTexture;

public:
	EnemyGenerator(sf::Texture& enemyTx, TileSet tileSet);

	void releaseEnemy(TileSet tileSet);

	void updateEnemies(TileSet& tileSet, GameState& gameState, float timeElapsed);

	void drawEnemies(sf::RenderWindow& window); 

	void setPosition(TileSet tileSet);

	void ifReachedFinish(GameState& gameState);

	void ereaseIfHit();

	std::vector<Enemy>& getEnemies();
};