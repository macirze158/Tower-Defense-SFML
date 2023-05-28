#include "shooterTower.h"

ShooterTower::ShooterTower(int posx, int posy, const sf::Texture& texture, sf::Texture& bulletTx) : Tower(posx, posy, texture, bulletTx)
{
	this->type = SHOOTER;
	this->rangeRadius = 200.f;
	this->price = 200;
	this->firingRate = 2.f;
}