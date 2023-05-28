#include "pathTile.h"

PathTile::PathTile(int grid_x, int grid_y, int posx, int posy, const sf::Texture& texture) : Tile(grid_x, grid_y, posx, posy, texture) {
	this->type = PATH;
};
