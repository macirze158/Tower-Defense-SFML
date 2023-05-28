#pragma once
#include "pathTile.h"

class StartTile : public  PathTile
{
public:
	StartTile(int grid_x, int grid_y, int posx, int posy, const sf::Texture& texture);
};