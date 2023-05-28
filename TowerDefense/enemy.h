#pragma once
#include "libIncludes.h"
#include "tileSet.h"
#include "gameState.h"

class Enemy : public sf::Sprite
{
private:
	float SPEED = 100.f; //const
	Tile* destination;
	bool reachedFinish = false;
	bool gotHit = false;

public:
	Enemy(int posx, int posy, const sf::Texture& texture, Tile* initialDestination);
	void followPath(TileSet& tileSet, GameState& gameState, float timeElapsed);
	bool isFinishReached();
	void setHitStatus(bool hitInfo);
	bool getHitStatus();

private:
	float getDistanceToDestination();
	void moveTowardsDestination(float distance);
};