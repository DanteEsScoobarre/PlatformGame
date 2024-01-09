#ifndef PLATFORMGAME_TILEMAP_H
#define PLATFORMGAME_TILEMAP_H
#include <vector>
#include "Tile.h"

class TileMap {
private:
    std::vector< std::vector<Tile*> > tiles;
    sf::Texture tileTexture;
    unsigned tileSize;

public:
    TileMap();
    TileMap(unsigned width, unsigned height, sf::Texture tileTexture, unsigned tileSize);
    ~TileMap();


    void addTileToTheBoard(unsigned x, unsigned y);
    void removeTileFromTheBoard(unsigned x, unsigned y);
    void updateTileMap();
    void renderTileMap(sf::RenderTarget& tileTarget);
};


#endif //PLATFORMGAME_TILEMAP_H
