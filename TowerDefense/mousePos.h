#pragma once
#include "libIncludes.h"
#include "gameState.h"
#include "towerManager.h"

class MousePosMenagement {
private:
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;
    sf::Font font;
    sf::Text posData;
    std::stringstream ss;
public:
    MousePosMenagement();
    ~MousePosMenagement();
    MousePosMenagement(std::string fontPath, int charSize);

    sf::Vector2i getMousePosScreen();

    sf::Vector2i getMousePosWindow(sf::RenderWindow& window);

    sf::Vector2f getMousePosView(sf::RenderWindow& window);

    sf::Vector2u getMousePosGrid(unsigned gridSizeU);

    void setPosDataInfo(std::stringstream& info);
    
    sf::Text getPosData();

    sf::Vector2f clickPos(sf::Event event, sf::RenderWindow& window);

    void buildTower(std::vector<sf::RectangleShape> towerBaseTilesPos, sf::Event event, sf::RenderWindow& window, TowerManager& towerManager, GameState& gameState,
        sf::Texture& shooterTx, sf::Texture& sniperTx, sf::Texture& bulletTx);
};