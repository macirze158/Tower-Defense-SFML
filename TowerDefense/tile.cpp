#include "tile.h"

Tile::Tile()
{

}

Tile::Tile(int grid_x, int grid_y, int posx, int posy, const sf::Texture &texture)
{
	this->shape.setTexture(&texture);
	this->shape.setSize(sf::Vector2f(grid_x, grid_y));
	this->shape.setPosition(static_cast<float>(grid_x) * posx, static_cast<float>(grid_y) * posy);
	this->posx = posx;
	this->posy = posy;
}

Tile::~Tile() {}

TileType Tile::getType()
{
	return this->type;
}

sf::RectangleShape Tile::getShape()
{
	return this->shape;
}

void Tile::drawTile(sf::RenderWindow& window)
{
	window.draw(this->shape);
}

bool Tile::isSelected(sf::Vector2f mousePos)
{
	return this->shape.getGlobalBounds().contains(mousePos);
}

//void Tile::actionWhenSelected(sf::RenderWindow& window, sf::Event event, MousePosMenagement& mousePos, TowerManager& towerManager, sf::Texture& shooterTx, sf::Texture& sniperTx, GameState& gameState, sf::Texture& bulletTx)
//{
//	if (isSelected(mousePos.clickPos(event, window)))
//	{
//		if (this->type == TOWER_BASE)
//		{
//			if (event.mouseButton.button == sf::Mouse::Left && gameState.getMoney() >= 200)
//			{
//				towerManager.addTower(ShooterTower(this->getGlobalPosition().x, this->getGlobalPosition().y, shooterTx, bulletTx));
//				gameState.setMoney(gameState.getMoney() - towerManager.getTowers().back().getPrice());
//			}
//			else if (event.mouseButton.button == sf::Mouse::Right && gameState.getMoney() >= 300)
//			{
//				towerManager.addTower(SniperTower(this->getGlobalPosition().x, this->getGlobalPosition().y, sniperTx, bulletTx));
//				gameState.setMoney(gameState.getMoney() - towerManager.getTowers().back().getPrice());
//			}
//		}
//	}
//}

int Tile::getPosX()
{
	return this->posx;
}
int Tile::getPosY()
{
	return this->posy;
}

sf::Vector2f Tile::getGlobalPosition() {
	float globalX = posx * grid_size_x + grid_size_x / 2;
	float globalY = posy * grid_size_y + grid_size_y / 2;
	return sf::Vector2f(globalX, globalY);
}
