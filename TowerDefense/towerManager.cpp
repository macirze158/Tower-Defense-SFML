#pragma once
#include "towerManager.h"

std::vector<Tower> TowerManager::getTowers()
{
	return this->towers;
}
void TowerManager::addTower(Tower newTower)
{
	this->towers.push_back(newTower);
}

void TowerManager::drawTowers(sf::RenderWindow& window)
{
	for (Tower tower : this->towers)
	{
		window.draw(tower);
	}
}
void TowerManager::drawAllBullets(sf::RenderWindow& window)
{
	for (Tower tower : this->towers)
	{
		tower.drawBullets(window);
	}
}
void TowerManager::updateTowerInfo(EnemyGenerator& enemyGen, sf::Texture& bulletTx, GameState& gameState, float timeElapsed)
{
	for (Tower& tower : this->towers)
	{
		tower.findTarget(enemyGen);
		tower.bulletGenerator(bulletTx);
		for (Bullet& bullet : tower.getBullets())
		{
			tower.shoot(gameState, timeElapsed, bullet);
		}

	}
	for (Tower& tower : this->towers)
	{
		tower.eraseBulletIfHit(gameState);
	}
}