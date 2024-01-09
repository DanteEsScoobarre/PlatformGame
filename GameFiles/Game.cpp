#include "Game.h"
#include "Player.h"
#include <fmt/core.h>

Game::Game() : window(sf::VideoMode(800, 600), "Platform Game"), player(){
    Game::initTileMap();
}



const sf::RenderWindow &Game::getWindow() const {
    return Game::window;
}

void Game::update() {
    Game::frameRateLimiter();
    while (Game::window.pollEvent(Game::event)) {
        if (Game::event.type == sf::Event::Closed) {
            Game::window.close();
        } else if (Game::event.type == sf::Event::KeyPressed && Game::event.key.code == sf::Keyboard::Escape) {
            Game::window.close();
        }
        if (Game::event.type == sf::Event::KeyReleased &&
            (Game::event.key.code == sf::Keyboard::Left || Game::event.key.code == sf::Keyboard::Right ||
             Game::event.key.code == sf::Keyboard::Up || Game::event.key.code == sf::Keyboard::Down)) {
            Game::player.animationTimerReset();
        }

    }
    Game::player.updatePlayer();
    Game::updateCollision();
    Game::updateTileMap();
}

void Game::render() {
    Game::window.clear();
    Game::renderTileMap();
    Game::renderPlayer();
    Game::window.display();
}

void Game::renderPlayer() {
    Game::player.renderPlayer(Game::window);
}

void Game::frameRateLimiter() {
    Game::window.setFramerateLimit(60);
}

void Game::updateCollision() {
    if (Game::player.getPlayerPosition().y + Game::player.getGlobalBoundsPlayer().height >
        Game::window.getSize().y) {
        Game::player.resetGravityVelocity();
        Game::player.setPlayerPosition(Game::player.getGlobalBoundsPlayer().left,
                                       Game::window.getSize().y - Game::player.getGlobalBoundsPlayer().height);
    }
}

void Game::initTileMap() {
    Game::tileMap = new TileMap();
}

void Game::renderTileMap() {
    Game::tileMap->renderTileMap(Game::window);
}

void Game::updateTileMap() {
        Game::tileMap->updateTileMap();
}

void Game::initTileTexture() {
if(!Game::tileTexture.loadFromFile("Textures/twilight-tiles.png")){
    fmt::println("Nie wczytano tekstur tiles");
}
}










