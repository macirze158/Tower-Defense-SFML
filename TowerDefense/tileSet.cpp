#include "tileSet.h"

TileSet::TileSet(sf::Texture & backgroundTx, sf::Texture & pathTx, sf::Texture & tower_baseTx, sf::Texture& startTx, sf::Texture& endTx) {
	readFromFile(backgroundTx, pathTx, tower_baseTx, startTx, endTx);
	setPath();
}

TileSet::~TileSet() {}

void TileSet::readFromFile(sf::Texture & backgroundTx, sf::Texture & pathTx, sf::Texture & tower_baseTx, sf::Texture& startTx, sf::Texture& endTx)
{
	std::regex fileNameRegex("map[0-9]*\\.txt");
	std::regex lineValidation("[1-5]{" + std::to_string(MAP_SIZE_X) + "}");
	std::filesystem::path path = std::filesystem::current_path();
	std::string fileName;
	std::string lineFromFile;
	int y = -1; //current line
	for (auto& entry : std::filesystem::directory_iterator(path))
	{
		fileName = std::filesystem::path(entry).filename().string();
		if (std::regex_match(fileName, fileNameRegex))
		{
			std::ifstream file;
			file.open(fileName);

			while (std::getline(file, lineFromFile))
			{
				y++;
				if (y < MAP_SIZE_Y && std::regex_match(lineFromFile, lineValidation))
				{
					for (int x = 0; x < lineFromFile.length(); x++)
					{
						switch (lineFromFile[x])
						{
						case BACKGROUND:
							this->tileSet[y][x] = BackgroundTile(gridSizeF, gridSizeF, x, y, backgroundTx);
							break;
						case PATH:
							this->tileSet[y][x] = PathTile(gridSizeF, gridSizeF, x, y, pathTx);
							break;
						case TOWER_BASE:
							this->tileSet[y][x] = TowerBaseTile(gridSizeF, gridSizeF, x, y, tower_baseTx);
							break;
						case START:
							this->tileSet[y][x] = StartTile(gridSizeF, gridSizeF, x, y, startTx);
							break;
						case END:
							this->tileSet[y][x] = EndTile(gridSizeF, gridSizeF, x, y, endTx);
							break;
						default:
							break;
						}
					}
				}
				else
				{
					file.close();
					throw std::exception("Data from the file does not match the criteria");
				}
			}
			file.close();
			return;
		}
	}
	throw std::exception("There is no valid map file");
	return;
}

void TileSet::drawTileSet(sf::RenderWindow& window)
{
	for (int x = 0; x < MAP_SIZE_X; x++)
		for (int y = 0; y < MAP_SIZE_Y; y++)
		{
			//this->tileSet[y][x].drawTile(window);
			tileSet[y][x].drawTile(window);
		}
}

Tile TileSet::getTile(int y, int x)
{
	return tileSet[y][x];
}

Tile* TileSet::getStart() {
	return entirePath[0];
}

void TileSet::setPath()
{
	for (int y = 0; y < MAP_SIZE_Y; y++)
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			if (this->tileSet[y][x].getType() == START)
			{
				this->entirePath.push_back(&tileSet[y][x]);
				break;
			}
		}
	Tile* prevTile = this->entirePath[0];
	Tile* currentTile = this->entirePath[0];

	int currentTileX;
	int currentTileY;
	while (currentTile->getType() != END)
	{
		currentTileY = currentTile->getPosY();
		currentTileX = currentTile->getPosX();
		if (currentTileX + 1 >= 0 && currentTileX < MAP_SIZE_X
			&& (this->tileSet[currentTileY][currentTileX + 1].getType() == PATH || this->tileSet[currentTileY][currentTileX + 1].getType() == END)
			&& (this->tileSet[currentTileY][currentTileX + 1].getPosX() != prevTile->getPosX() || this->tileSet[currentTileY][currentTileX + 1].getPosY() != prevTile->getPosY()))
		{
			prevTile = currentTile;
			currentTile = &this->tileSet[currentTileY][currentTileX + 1];
			this->entirePath.push_back(currentTile);
		}
		else if (currentTileX - 1 >= 0 && currentTileX < MAP_SIZE_X
			&& (this->tileSet[currentTileY][currentTileX - 1].getType() == PATH || this->tileSet[currentTileY][currentTileX - 1].getType() == END)
			&& (this->tileSet[currentTileY][currentTileX - 1].getPosX() != prevTile->getPosX() || this->tileSet[currentTileY][currentTileX - 1].getPosY() != prevTile->getPosY()))
		{
			prevTile = currentTile;
			currentTile = &this->tileSet[currentTileY][currentTileX - 1];
			this->entirePath.push_back(currentTile);
		}
		else if (currentTileY + 1 >= 0 && currentTileY < MAP_SIZE_Y
			&& (this->tileSet[currentTileY+1][currentTileX].getType() == PATH || this->tileSet[currentTileY + 1][currentTileX].getType() == END)
			&& (this->tileSet[currentTileY+1][currentTileX].getPosX() != prevTile->getPosX() || this->tileSet[currentTileY+1][currentTileX].getPosY() != prevTile->getPosY()))
		{
			prevTile = currentTile;
			currentTile = &this->tileSet[currentTileY+1][currentTileX];
			this->entirePath.push_back(currentTile);
		}
		else if (currentTileY - 1 >= 0 && currentTileY < MAP_SIZE_Y
			&& (this->tileSet[currentTileY-1][currentTileX].getType() == PATH || this->tileSet[currentTileY - 1][currentTileX].getType() == END)
			&& (this->tileSet[currentTileY-1][currentTileX].getPosX() != prevTile->getPosX() || this->tileSet[currentTileY-1][currentTileX].getPosY() != prevTile->getPosY()))
		{
			prevTile = currentTile;
			currentTile = &this->tileSet[currentTileY-1][currentTileX];
			this->entirePath.push_back(currentTile);
		}
	}
}

std::vector <Tile*> TileSet::getEntirePath()
{
	return this->entirePath;
}