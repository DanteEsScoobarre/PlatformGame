#ifndef PLATFORMGAME_TILE_H
#define PLATFORMGAME_TILE_H
#include <SFML/Graphics.hpp>

class Tile {
private:
    sf::Sprite tileSprite;
    bool damaging;
public:
    Tile(sf::Texture& tile_texture, sf::IntRect tile_rect, bool damaging);
    void tileUpdate();
    void tileRender(sf::RenderTarget& tileTarget);


};


#endif //PLATFORMGAME_TILE_H
