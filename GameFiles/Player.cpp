#include "Player.h"
#include <fmt/core.h>
void Player::initSprite() {
    Player::sprite.setTexture(Player::textures);
}

void Player::initTextures() {
    if (!Player::textures.loadFromFile("C:\\Users\\rozsh\\CLionProjects\\PlatformGame\\Textures\\elisa-spritesheet1.png")){
        fmt::println("Failed to load player textures");
    }
}
Player::Player(){
    Player::initSprite();
    Player::initTextures();
}


void Player::updatePlayer() {

}

void Player::renderPlayer(sf::RenderTarget &playerTarget) {
    playerTarget.draw(Player::sprite);
}




