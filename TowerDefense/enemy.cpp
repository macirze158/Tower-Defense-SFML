#include "enemy.h"

Enemy::Enemy(int posx,int posy, const sf::Texture& texture, Tile* initialDestination)
{
	this->setTexture(texture);
	this->setPosition(posx, posy);
	this->setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	this->destination = initialDestination;
}

void Enemy::followPath(TileSet& tileSet, GameState& gameState, float timeElapsed)
{
	float distance = SPEED * timeElapsed;

	if (getDistanceToDestination() > distance) {
		moveTowardsDestination(distance);
	}
	else {
		setPosition(sf::Vector2f(destination->getGlobalPosition().x, destination->getGlobalPosition().y));
		bool foundNextDestination = false;
		std::vector <Tile*> path = tileSet.getEntirePath();
		for (int i = 0; i < path.size() - 1; i++)
		{
			if (destination == path[i]) {
				destination = path[i + 1];
				foundNextDestination = true;
				break;
			}
		}
		reachedFinish = !foundNextDestination;
	}
}

bool Enemy::isFinishReached() {
	return reachedFinish;
}

float Enemy::getDistanceToDestination() {
	float distanceX = abs(destination->getGlobalPosition().x - getPosition().x);
	float distanceY = abs(destination->getGlobalPosition().y - getPosition().y);
	if (distanceX < distanceY) {
		return distanceY;
	}
	else {
		return distanceX;
	}
}

void Enemy::moveTowardsDestination(float distance) {
	float distanceX = abs(destination->getGlobalPosition().x - getPosition().x);
	float distanceY = abs(destination->getGlobalPosition().y - getPosition().y);
	if (distanceX < distanceY) {
		if (destination->getGlobalPosition().y - getPosition().y > 0) {
			move(0.f, distance);
		}
		else {
			move(0.f, -distance);
		}
	}
	else {
		if (destination->getGlobalPosition().x - getPosition().x > 0) {
			move(distance, 0.f);
		}
		else {
			move(-distance, 0.f);
		}
	}
}

void Enemy::setHitStatus(bool hitInfo)
{
	this->gotHit = hitInfo;
}

bool Enemy::getHitStatus()
{
	return this->gotHit;
}
