#ifndef PLATFORMGAME_GAME_H
#define PLATFORMGAME_GAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game{
public:
    Game();
    virtual ~Game();
    //Rendering okna
    const sf::RenderWindow& getWindow() const;
    void update();
    void render();
    void renderPlayer();

private:
sf::RenderWindow window;
sf::Event event{};
Player player;



};
#endif //PLATFORMGAME_GAME_H
