#include "tile.h"
#include "pathTile.h"
#include "towerBaseTile.h"
#include "backgroundTile.h"
#include "mousePos.h"
#include "tileSelector.h"
#include "gameState.h"
#include "tileSet.h"
#include "enemy.h"
#include "enemyGenerator.h"
#include "tower.h"
#include "sniperTower.h"
#include "shooterTower.h"
#include "towerManager.h"

int main()
{
    //loading textures
    sf::Texture pathTx;
    if (!pathTx.loadFromFile("resources\\path.png"))
        return -1;

    sf::Texture backgroundTx;
    if (!backgroundTx.loadFromFile("resources\\background.png"))
        return -1;

    sf::Texture tower_baseTx;
    if (!tower_baseTx.loadFromFile("resources\\tower_base.png"))
        return -1;

    sf::Texture startTx;
    if (!startTx.loadFromFile("resources\\start.png"))
        return -1;

    sf::Texture endTx;
    if (!endTx.loadFromFile("resources\\end.png"))
        return -1;
    
    sf::Texture enemyTx;
    if (!enemyTx.loadFromFile("resources\\enemy.png"))
        return -1;

    sf::Texture shooterTx;
    if (!shooterTx.loadFromFile("resources\\shooter_tower.png"))
        return -1;

    sf::Texture sniperTx;
    if (!sniperTx.loadFromFile("resources\\sniper_tower.png"))
        return -1;

    sf::Texture bulletTx;
    if (!bulletTx.loadFromFile("resources\\bullet.png"))
        return -1;



    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tower Defense - Maciej Rzeznik", sf::Style::Titlebar | sf::Style::Close);
    MousePosMenagement mousePos("resources\\OpenSans-Light.ttf", 20);   
    GameState gameState("resources\\OpenSans-Light.ttf", 30, 500, 0, 10);

    try {
        TileSet tileSet = TileSet(backgroundTx, pathTx, tower_baseTx, startTx, endTx);
        TileSelector tileSelector(gridSizeF, gridSizeF);
        EnemyGenerator enemyGen(enemyTx, tileSet);
        TowerManager towerManager;
        sf::Clock frameTimer;
        std::vector<sf::RectangleShape> towerBaseTilesPos;
        for (int y = 0; y < MAP_SIZE_Y; y++)
            for (int x = 0; x < MAP_SIZE_X; x++)
            {
                if (tileSet.getTile(y, x).getType() == TOWER_BASE)
                {
                    sf::RectangleShape tmp;
                    tmp.setSize(sf::Vector2f(gridSizeF, gridSizeF));
                    tmp.setPosition(tileSet.getTile(y, x).getGlobalPosition().x, tileSet.getTile(y, x).getGlobalPosition().y);
                    tmp.setOrigin(tmp.getGlobalBounds().width / 2, tmp.getGlobalBounds().height / 2);
                    towerBaseTilesPos.push_back(tmp);
                }
            }
        while (window.isOpen())
        {
            float frameTime = frameTimer.restart().asSeconds();

            //
            std::stringstream ss;
            ss << "Screen Position: " << mousePos.getMousePosScreen().x << " " << mousePos.getMousePosScreen().y << "\n"
                << "Window Position: " << mousePos.getMousePosWindow(window).x << " " << mousePos.getMousePosWindow(window).y << "\n"
                << "View Position: " << mousePos.getMousePosView(window).x << " " << mousePos.getMousePosView(window).y << "\n"
                << "Grid Position: " << mousePos.getMousePosGrid(gridSizeU).x << " " << mousePos.getMousePosGrid(gridSizeU).y << "\n";
            mousePos.setPosDataInfo(ss);
            //


            tileSelector.setPosition(mousePos.getMousePosGrid(gridSizeU).x * gridSizeF, mousePos.getMousePosGrid(gridSizeU).y * gridSizeF);

            sf::Event event;
            while (window.pollEvent(event))
            {

                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed)
                    mousePos.buildTower(towerBaseTilesPos, event, window, towerManager, gameState, shooterTx, sniperTx, bulletTx);
                    
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                return 0;


            towerManager.updateTowerInfo(enemyGen, bulletTx, gameState, frameTime);
            
            std::async(std::launch::async, &GameState::updateData, &gameState);

            std::thread t2(&EnemyGenerator::updateEnemies, &enemyGen, std::ref(tileSet), std::ref(gameState), frameTime);
            std::thread t3(&EnemyGenerator::ifReachedFinish, &enemyGen, std::ref(gameState));
            t2.join();
            t3.join();

            enemyGen.ereaseIfHit();

            //drawing
            window.clear();
            
            tileSet.drawTileSet(window);

            enemyGen.releaseEnemy(tileSet);
            enemyGen.drawEnemies(window);

            tileSelector.drawTileSelector(window, gridSizeU, mousePos, MAP_SIZE_X, MAP_SIZE_Y);

            towerManager.drawTowers(window);
            towerManager.drawAllBullets(window);
            window.draw(gameState.getData());
            gameState.drawGameOver(window);
            window.display();
        }
    }
    catch (std::exception ex) {
        std::cout << ex.what();
        return 0;
    }

    return 0;
}