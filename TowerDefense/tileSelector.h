#pragma once
#include "libIncludes.h"
#include "mousePos.h"

class TileSelector{
private:
	sf::RectangleShape tile;
public:
	TileSelector(float gridSizeX, float gridSizeY);
	void setPosition(float mousePosX, float mousePosY);
	void drawTileSelector(sf::RenderWindow& window, unsigned gridSizeU, MousePosMenagement& mousePos, const int mapSizeX, const int mapSizeY);
};