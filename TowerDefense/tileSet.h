#pragma once
#include "libIncludes.h"
#include "tile.h"
#include "backgroundTile.h"
#include "pathTile.h"
#include "towerBaseTile.h"
#include "startTile.h"
#include "endTile.h"
//#include "mousePos.h"

class TileSet
{
private:
	Tile tileSet[MAP_SIZE_Y][MAP_SIZE_X];
	std::vector <Tile*> entirePath;
public:

	TileSet(sf::Texture& backgroundTx, sf::Texture& pathTx, sf::Texture& tower_baseTx, sf::Texture& startTx, sf::Texture& endTx);

	~TileSet();
	
	void readFromFile(sf::Texture& backgroundTx, sf::Texture& pathTx, sf::Texture& tower_baseTx, sf::Texture& startTx, sf::Texture& endTx);

	void drawTileSet(sf::RenderWindow& window);

	Tile getTile(int y, int x);

	Tile* getStart();

	std::vector <Tile*> getEntirePath();

	void setPath();
};