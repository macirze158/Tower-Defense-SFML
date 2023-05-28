#pragma once
#include "libIncludes.h"
#include "enemyGenerator.h"
#include "bullet.h"

enum TowerType {SHOOTER = '1', SNIPER};

class Tower : public sf::Sprite
{
protected:
	int rangeRadius;
	TowerType type;
	float firingRate;
	int price;
	Enemy* target = nullptr;
	sf::Clock shootingTimer;
	std::vector<Bullet> bullets;
	sf::Texture bulletTexture;
	float SPEED = 900.f; //const
public:
	Tower(int posx, int posy, const sf::Texture& texture, sf::Texture& bulletTx);
	int getPrice();
	void findTarget(EnemyGenerator& enemyGen);
	void bulletGenerator(sf::Texture& bulletTx);
	void drawBullets(sf::RenderWindow& window);
	bool collision(Bullet bullet);
	void shoot(GameState& gameState, float timeElapsed, Bullet& bullet);
	//float getDistanceToTarget(Bullet bullet);
	void moveTowardsTarget(float distance, Bullet& bullet);
	void eraseBulletIfHit(GameState& gameState);
	std::vector<Bullet>& getBullets();
};