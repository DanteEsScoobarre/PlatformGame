#include "Game.h"
#include "Player.h"
#include <fmt/core.h>

    Game::Game() : window(sf::VideoMode(800, 600), "Platform Game"), player(){

    }
   Game::~Game(){

    }



const sf::RenderWindow &Game::getWindow() const{
    return Game::window;
}

void Game::update() {
while (Game::window.pollEvent(Game::event)){
    if (Game::event.type == sf::Event::Closed){
        Game::window.close();
    }else if (Game::event.type == sf::Event::KeyPressed && Game::event.key.code == sf::Keyboard::Escape){
        Game::window.close();
    }

}
    Game::player.updatePlayer();
}

void Game::render() {
    Game::window.clear();
    Game::renderPlayer();
    Game::window.display();
}

void Game::renderPlayer() {
    Game::player.renderPlayer(Game::window);
}







