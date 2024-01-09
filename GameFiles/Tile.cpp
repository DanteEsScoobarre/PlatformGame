//
// Created by rozsh on 09/01/2024.
//

#include "Tile.h"

Tile::Tile(sf::Texture& tile_texture, sf::IntRect tile_rect, bool damaging) : damaging(damaging) {
    Tile::tileSprite.setTexture(tile_texture);
    Tile::tileSprite.setTextureRect(tile_rect);


}

void Tile::tileUpdate() {

}

void Tile::tileRender(sf::RenderTarget& tileTarget) {
    tileTarget.draw(Tile::tileSprite);
}
