#include "tileSelector.h"

TileSelector::TileSelector(float gridSizeX, float gridSizeY)
{
	tile.setSize(sf::Vector2f(gridSizeX, gridSizeY));
	tile.setFillColor(sf::Color::Transparent);
	tile.setOutlineThickness(5.f);
	tile.setOutlineColor(sf::Color::Red);
}
void TileSelector::setPosition(float mousePosX, float mousePosY)
{
	tile.setPosition(mousePosX, mousePosY);
}
void TileSelector::drawTileSelector(sf::RenderWindow& window, unsigned gridSizeU, MousePosMenagement& mousePos, const int mapSizeX, const int mapSizeY)
{
	if (mousePos.getMousePosGrid(gridSizeU).x < mapSizeX && mousePos.getMousePosGrid(gridSizeU).y < mapSizeY)
		window.draw(tile);
}