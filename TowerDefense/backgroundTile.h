#pragma once
#include "libIncludes.h"
#include "tile.h"

class BackgroundTile : public Tile
{
public:
	BackgroundTile();
	BackgroundTile(int grid_x, int grid_y, int posx, int posy, const sf::Texture& texture);
};