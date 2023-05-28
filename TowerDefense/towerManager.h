#pragma once
#include "libIncludes.h"
#include "shooterTower.h"
#include "sniperTower.h"

class TowerManager
{
private:
	std::vector<Tower> towers;
public:
	
	std::vector<Tower> getTowers();
	void addTower(Tower newTower);
	void drawTowers(sf::RenderWindow& window);
	void drawAllBullets(sf::RenderWindow& window);
	void updateTowerInfo(EnemyGenerator& enemyGen, sf::Texture& bulletTx, GameState& gameState, float timeElapsed);
};