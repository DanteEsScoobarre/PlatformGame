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
    sf::IntRect currentFrame;
    void initSprite();
    void initTextures();
    void movement();

};


#endif //PLATFORMGAME_PLAYER_H
