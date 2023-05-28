#include "tower.h"

Tower::Tower(int posx, int posy, const sf::Texture& texture, sf::Texture& bulletTx)
{
	this->setTexture(texture);
	this->setPosition(posx, posy);
	this->setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	this->bulletTexture = bulletTx;
}

int Tower::getPrice()
{
	return this->price;
}

void Tower::findTarget(EnemyGenerator& enemyGen)
{
	int distance;
	for (Enemy& enemy : enemyGen.getEnemies())
	{
		distance = sqrt(pow(this->getPosition().x - enemy.getPosition().x, 2) + pow(this->getPosition().y - enemy.getPosition().y, 2));
		if (distance <= this->rangeRadius )
		{
			this->target = &enemy;
			break;
		}
	}
}

void Tower::bulletGenerator(sf::Texture& bulletTx)
{
	if (shootingTimer.getElapsedTime().asSeconds() >= firingRate && target != nullptr) {
		this->bullets.push_back(Bullet(this->getPosition().x, this->getPosition().y, bulletTx));
		shootingTimer.restart();
	}
}

void Tower::drawBullets(sf::RenderWindow& window)
{
	for (Bullet bullet : this->bullets)
	{
		window.draw(bullet);
	}
}

bool Tower::collision(Bullet bullet)
{
	float distance;
	distance = sqrt(pow(bullet.getPosition().x - target->getPosition().x, 2) + pow(bullet.getPosition().y - target->getPosition().y, 2));
	return bullet.getLocalBounds().height / 2 + target->getLocalBounds().height / 2 > distance;
}

void Tower::shoot(GameState& gameState, float timeElapsed, Bullet& bullet)
{
	float distance = SPEED * timeElapsed;
	moveTowardsTarget(distance, bullet);
	if (collision(bullet))
	{
		target->setHitStatus(true);
		bullet.setHitStatus(true);
		target = nullptr;
	}
}

//float Tower::getDistanceToTarget(Bullet bullet) {
//	float distanceX = abs(target->getPosition().x - bullet.getPosition().x);
//	float distanceY = abs(target->getPosition().y - bullet.getPosition().y);
//	if (distanceX < distanceY) {
//		return distanceY;
//	}
//	else {
//		return distanceX;
//	}
//}

void Tower::moveTowardsTarget(float distance, Bullet& bullet) {
	sf::Vector2f direction = target->getPosition() - bullet.getPosition();
	float directionVectorLength = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	direction /= directionVectorLength;
	sf::Vector2f offset = direction * distance;
	bullet.move(offset);
}

std::vector<Bullet>& Tower::getBullets()
{
	return this->bullets;
}

void Tower::eraseBulletIfHit(GameState& gameState)
{
	int maxVectorIndex = this->bullets.size() - 1;
	for (int i = maxVectorIndex; i >= 0; i--)
	{
		if (this->bullets[i].getHitStatus() == true)
		{
			this->bullets.erase(this->bullets.begin() + i);
			gameState.setScore(gameState.getScore() + 5);
			gameState.setMoney(gameState.getMoney() + 5);
		}
	}
}