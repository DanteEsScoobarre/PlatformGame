#include "TileMap.h"

TileMap::TileMap() {
    TileMap::tileSize = 0;
}

TileMap::TileMap(unsigned int width, unsigned int height, sf::Texture tileTexture, unsigned int tileSize) {
    TileMap::tileTexture = tileTexture;
    TileMap::tileSize = tileSize;
    TileMap::tiles.resize(width);
    for (int i = 0; i < TileMap::tiles.size(); i++){
        TileMap::tiles[i].resize(height, nullptr);
    }
}

TileMap::~TileMap() {
    for (int i = 0; i < TileMap::tiles.size(); i++){
        for (int  j = 0; j < TileMap::tiles.size(); j++) {
            TileMap::tiles[i][j] = nullptr;
        }
    }
}

void TileMap::addTileToTheBoard(unsigned int x, unsigned int y) {
    if(x < TileMap::tiles.size()){
        if(y < TileMap::tiles[x].size()){
            if(TileMap::tiles[x][y] == nullptr){
                TileMap::tiles[x][y] = new Tile(TileMap::tileTexture, sf::IntRect(0, 0, TileMap::tileSize, TileMap::tileSize),
                                                false);
            }

        }
    }
}

void TileMap::removeTileFromTheBoard(unsigned int x, unsigned int y) {
    if(x < TileMap::tiles.size()){
        if(y < TileMap::tiles[x].size()){
            if(TileMap::tiles[x][y] != nullptr){
                delete TileMap::tiles[x][y];
                TileMap::tiles[x][y] = nullptr;
            }

        }
    }
}

void TileMap::updateTileMap() {
    for (int i = 0; i < TileMap::tiles.size(); i++){
        for (int  j = 0; j < TileMap::tiles.size(); j++) {
            if (TileMap::tiles[i][j] != nullptr) {
                TileMap::tiles[i][j]->tileUpdate();
            }
        }
    }
}



void TileMap::renderTileMap(sf::RenderTarget &tileTarget) {
    for (int i = 0; i < TileMap::tiles.size(); i++){
        for (int  j = 0; j < TileMap::tiles.size(); j++) {
            if (TileMap::tiles[i][j] != nullptr) {
                TileMap::tiles[i][j]->tileRender(tileTarget);
            }
        }
    }
}
