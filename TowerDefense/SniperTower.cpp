#include "sniperTower.h"

SniperTower::SniperTower(int posx, int posy, const sf::Texture& texture, sf::Texture& bulletTx) : Tower(posx, posy, texture, bulletTx)
{
	this->type = SNIPER;
	this->rangeRadius = 600.f;
	this->price = 300;
	this->firingRate = 5.f;
}