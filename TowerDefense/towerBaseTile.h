#pragma once
#include "libIncludes.h"
#include "tile.h"
#include "tileSet.h"

class TowerBaseTile : public Tile
{
public:
	TowerBaseTile(int grid_x, int grid_y, int posx, int posy, const sf::Texture& texture);
};