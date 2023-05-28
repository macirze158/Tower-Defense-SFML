#include "enemyGenerator.h"

EnemyGenerator::EnemyGenerator(sf::Texture& enemyTx, TileSet tileSet)
{
	this->enemyTexture = enemyTx;
	setPosition(tileSet);
}

void EnemyGenerator::releaseEnemy(TileSet tileSet) {
	if (releaseTimer.getElapsedTime().asSeconds() >= releaseTime) {
		enemies.push_back(Enemy(position.x, position.y, enemyTexture, tileSet.getStart()));
		releaseTime *= RELEASE_SPEED_UP;
		RELEASE_SPEED_UP += 0.025f * (1.f - RELEASE_SPEED_UP);
		releaseTimer.restart();
	}
}

void EnemyGenerator::updateEnemies(TileSet& tileSet, GameState& gameState, float timeElapsed) {
	for (Enemy& enemy : this->enemies) {
		enemy.followPath(tileSet, gameState, timeElapsed);
	}
}

void EnemyGenerator::drawEnemies(sf::RenderWindow& window) {
	for (Enemy enemy : this->enemies) {
		window.draw(enemy);
	}
}
void EnemyGenerator::setPosition(TileSet tileSet)
{
	std::vector <Tile*> path = tileSet.getEntirePath();
	this->position.x = path[0]->getGlobalPosition().x;
	this->position.y = path[0]->getGlobalPosition().y;
}

void EnemyGenerator::ifReachedFinish(GameState& gameState)
{
	int maxVectorIndex = this->enemies.size() - 1;
	for (int i = maxVectorIndex; i >= 0; i--)
	{
		if (this->enemies[i].isFinishReached())
		{
			this->enemies.erase(this->enemies.begin() + i);
			if(gameState.getHealthPoints() > 0)
				gameState.setHealtPoints(gameState.getHealthPoints() - 1);
		}
	}
}

std::vector<Enemy>& EnemyGenerator::getEnemies()
{
	return this->enemies;
}

void EnemyGenerator::ereaseIfHit()
{
	int maxVectorIndex = this->enemies.size() - 1;
	for (int i = maxVectorIndex; i >= 0; i--)
	{
		if (this->enemies[i].getHitStatus())
		{
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}