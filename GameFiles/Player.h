#ifndef PLATFORMGAME_PLAYER_H
#define PLATFORMGAME_PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void updatePlayer();
    void renderPlayer(sf::RenderTarget & playerTarget);


private:
    sf::Sprite sprite;
    sf::Texture textures;
    void initSprite();
    void initTextures();

};


#endif //PLATFORMGAME_PLAYER_H
