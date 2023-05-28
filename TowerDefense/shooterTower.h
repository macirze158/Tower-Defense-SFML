#pragma once
#include "tower.h"

class ShooterTower : public Tower
{
public:
	ShooterTower(int posx, int posy, const sf::Texture& texture, sf::Texture& bulletTx);
};