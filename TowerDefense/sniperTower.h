#pragma once
#include "tower.h"

class SniperTower : public Tower
{
public:
	SniperTower(int posx, int posy, const sf::Texture& texture, sf::Texture& bulletTx);
};