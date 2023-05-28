#include "mousePos.h"

MousePosMenagement::MousePosMenagement() {};
MousePosMenagement::~MousePosMenagement() {};
MousePosMenagement::MousePosMenagement(std::string fontPath, int charSize)
{
    font.loadFromFile(fontPath);
    posData.setCharacterSize(charSize);
    posData.setFillColor(sf::Color::White);
    posData.setFont(font);
    posData.setString("Position Data");
}

sf::Vector2i MousePosMenagement::getMousePosScreen()
{
    return this->mousePosScreen = sf::Mouse::getPosition();
}

sf::Vector2i MousePosMenagement::getMousePosWindow(sf::RenderWindow& window)
{
    return this->mousePosWindow = sf::Mouse::getPosition(window);
}

sf::Vector2f MousePosMenagement::getMousePosView(sf::RenderWindow& window)
{
    return this->mousePosView = window.mapPixelToCoords(this->mousePosWindow);
}

sf::Vector2u MousePosMenagement::getMousePosGrid(unsigned gridSizeU)
{
    if (mousePosView.x >= 0.f)
        mousePosGrid.x = mousePosView.x / gridSizeU;
    if (mousePosView.y >= 0.f)
        mousePosGrid.y = mousePosView.y / gridSizeU;
    return mousePosGrid;
}

void MousePosMenagement::setPosDataInfo(std::stringstream& info)
{
    posData.setString(info.str());
}
sf::Text MousePosMenagement::getPosData()
{
    return this->posData;
}

sf::Vector2f MousePosMenagement::clickPos(sf::Event event, sf::RenderWindow& window)
{

    if (event.type == sf::Event::MouseButtonPressed)
        {
            //std::cout << this->getMousePosView(window).x << " " << this->getMousePosView(window).y << std::endl;
            return this->getMousePosView(window);
        }
}

void MousePosMenagement::buildTower(std::vector<sf::RectangleShape> towerBaseTilesPos, sf::Event event, sf::RenderWindow& window, 
    TowerManager& towerManager, GameState& gameState, sf::Texture& shooterTx, sf::Texture& sniperTx, sf::Texture& bulletTx)
{
    for (sf::RectangleShape shape : towerBaseTilesPos)
    {
        if (shape.getGlobalBounds().contains(clickPos(event, window)))
        {
            if (event.mouseButton.button == sf::Mouse::Left && gameState.getMoney() >= 200)
            {
                towerManager.addTower(ShooterTower(shape.getPosition().x, shape.getPosition().y, shooterTx, bulletTx));
                gameState.setMoney(gameState.getMoney() - towerManager.getTowers().back().getPrice());
            }
            else if (event.mouseButton.button == sf::Mouse::Right && gameState.getMoney() >= 300)
            {
                towerManager.addTower(SniperTower(shape.getPosition().x, shape.getPosition().y, sniperTx, bulletTx));
                gameState.setMoney(gameState.getMoney() - towerManager.getTowers().back().getPrice());
            }
        }
    }
}