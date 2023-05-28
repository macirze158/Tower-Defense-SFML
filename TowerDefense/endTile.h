#pragma once
#include "pathTile.h"

class EndTile : public  PathTile
{
public:
	EndTile(int grid_x, int grid_y, int posx, int posy, const sf::Texture& texture);
};