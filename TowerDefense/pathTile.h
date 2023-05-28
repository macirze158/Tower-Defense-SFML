#pragma once
#include "libIncludes.h"
#include "tile.h"

class PathTile : public Tile
{
public:
	PathTile(int grid_x, int grid_y, int posx, int posy, const sf::Texture& texture);

};
