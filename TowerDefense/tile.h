#pragma once
#include "libIncludes.h"
//#include "mousePos.h"
//#include "gameState.h"
//#include "towerManager.h"


enum TileType {BACKGROUND = '1', PATH, TOWER_BASE, START, END};

class Tile
{
protected:
	sf::RectangleShape shape;
	TileType type;
	int posx;
	int posy;
	int grid_size_y = gridSizeF;
	int grid_size_x = gridSizeF;
public:
	Tile();
	Tile(int grid_x, int grid_y, int posx, int posy, const sf::Texture &texture);
	~Tile();

	TileType getType();
	sf::RectangleShape getShape();
	void drawTile(sf::RenderWindow& window);
	bool isSelected(sf::Vector2f mousePos);
	//void actionWhenSelected(sf::RenderWindow& window, sf::Event event, MousePosMenagement& mousePos, TowerManager& towerManager, sf::Texture& shooterTx, sf::Texture& sniperTx, GameState& gameState, sf::Texture& bulletTx);
	int getPosX();
	int getPosY();
	sf::Vector2f getGlobalPosition();
};