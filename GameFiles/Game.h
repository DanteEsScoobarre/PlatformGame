#ifndef PLATFORMGAME_GAME_H
#define PLATFORMGAME_GAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileMap.h"

class Game{
public:
    Game();
    //Rendering okna
    const sf::RenderWindow& getWindow() const;
    void update();
    void render();
    void renderPlayer();
    void frameRateLimiter();
    void updateCollision();
    void initTileTexture();
    void initTileMap();
    void updateTileMap();
    void renderTileMap();

private:
sf::RenderWindow window;
sf::Event event;
Player player;
sf::Texture tileTexture;
TileMap* tileMap;


};
#endif //PLATFORMGAME_GAME_H
