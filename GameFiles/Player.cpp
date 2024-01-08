#include "Player.h"
#include "Game.h"
#include <fmt/core.h>
void Player::initSprite() {
    Player::sprite.setTexture(Player::textures);
    Player::currentFrame = sf::IntRect(0, 0, 60, 60);
    Player::sprite.setTextureRect(Player::currentFrame);
}

void Player::initTextures() {
    if (!Player::textures.loadFromFile("C:\\Users\\rozsh\\CLionProjects\\PlatformGame\\Textures\\elisa-spritesheet1.png")){
        fmt::println("Failed to load player textures");
    }
}
Player::Player(){
    Player::initTextures();
    Player::initSprite();

}


void Player::updatePlayer() {
    Player::movement();
}

void Player::renderPlayer(sf::RenderTarget &playerTarget) {
    playerTarget.draw(Player::sprite);
}

void Player::movement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        Player::sprite.move(-1.f, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        Player::sprite.move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        Player::sprite.move(0.f, -1.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        Player::sprite.move(0.f, 1.f);
    }
}




