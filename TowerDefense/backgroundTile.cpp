#include "backgroundTile.h"

BackgroundTile::BackgroundTile() {};
BackgroundTile::BackgroundTile(int grid_x, int grid_y, int posx, int posy, const sf::Texture& texture) : Tile(grid_x, grid_y, posx, posy, texture) {
	this->type = BACKGROUND;
};

