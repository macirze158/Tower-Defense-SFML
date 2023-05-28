#include "startTile.h"

StartTile::StartTile(int grid_x, int grid_y, int posx, int posy, const sf::Texture& texture) : PathTile(grid_x, grid_y, posx, posy, texture)
{
	this->type = START;
}