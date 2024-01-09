#include "Player.h"
#include <fmt/core.h>


void Player::initSprite() {
    Player::sprite.setTexture(Player::textures);
    Player::currentFrame = sf::IntRect(0, 0, 32, 32);
    Player::sprite.setTextureRect(Player::currentFrame);
    Player::sprite.setScale(3.f, 3.f);
}

void Player::initTextures() {
    if (!Player::textures.loadFromFile(
            "C:\\Users\\rozsh\\CLionProjects\\PlatformGame\\Textures\\rogue spritesheet calciumtrice.png")) {
        fmt::println("Failed to load player textures");
    }
}

Player::Player() {
    Player::initTextures();
    Player::initSprite();
    Player::initAnimations();
    Player::initPhysics();

}


void Player::updatePlayer() {
    Player::movement();
    Player::updateAnimatons();
    Player::updatePhysics();

}

void Player::renderPlayer(sf::RenderTarget &playerTarget) {
    playerTarget.draw(Player::sprite);
}

void Player::movement() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        Player::movePlayer(-0.3f, 0.f);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        Player::movePlayer(0.3f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Player::canJump) {
        Player::currentAnimState = PlayerAnimState::Jumping;
        Player::velocity.y = -70.f;
        Player::canJump = false;

    }
    if (Player::velocity.x > 0.f) {
        Player::currentAnimState = PlayerAnimState::MovingRight;
    }else if (Player::velocity.x < 0.f){
        Player::currentAnimState = PlayerAnimState::MovingLeft;
    } else{
        Player::currentAnimState = PlayerAnimState::Idle;
    }

}


void Player::initAnimations() {
    Player::animationTimer.restart();
    Player::SwitchAnimation = true;
}

void Player::updateAnimatons() {
    if (Player::currentAnimState == PlayerAnimState::Idle) {
        if (Player::animationTimer.getElapsedTime().asSeconds() >= 0.3f) {
            Player::currentFrame.top = 0.f;
            Player::currentFrame.left += 32.f;
            if (Player::currentFrame.left >= 288.f) {
                Player::currentFrame.left = 0;
            }
            Player::animationTimer.restart();
            Player::sprite.setTextureRect(Player::currentFrame);
        }

    } else if (Player::currentAnimState == PlayerAnimState::MovingRight) {
        if (Player::animationTimer.getElapsedTime().asSeconds() >= 0.11f) {
            Player::currentFrame.top = 64.f;
            Player::currentFrame.left += 32.f;
            if (Player::currentFrame.left >= 288.f) {
                Player::currentFrame.left = 0;
            }
            Player::animationTimer.restart();
            Player::sprite.setTextureRect(Player::currentFrame);

        }
        Player::sprite.setScale(3.f, 3.f);
        Player::sprite.setOrigin(Player::sprite.getGlobalBounds().width / 3.f, 0.f);
    } else if (Player::currentAnimState == PlayerAnimState::MovingLeft) {
        if (Player::animationTimer.getElapsedTime().asSeconds() >= 0.11f) {
            Player::currentFrame.top = 64.f;
            Player::currentFrame.left += 32.f;
            if (Player::currentFrame.left >= 288.f) {
                Player::currentFrame.left = 0;
            }
            Player::animationTimer.restart();
            Player::sprite.setTextureRect(Player::currentFrame);
            Player::sprite.setScale(-3.f, 3.f);
        }
        Player::sprite.setOrigin(Player::sprite.getGlobalBounds().width / 3.f, 0.f);
    }

}

void Player::initPhysics() {
    Player::maxVelocity = 10.f;
    Player::minVelocity = 0.3f;
    Player::speedingUp = 0.3f;
    Player::airResistance = 0.95f;
    Player::gravity = 4.f;
    Player::maxGravityVelocity = 15.f;


}

void Player::updatePhysics() {
    Player::velocity.y += 1.0f * Player::gravity;
    if (std::abs(Player::velocity.y) > maxGravityVelocity) {
        Player::velocity.y = maxGravityVelocity * ((Player::velocity.y < 0.f) ? -1.f : 1.f);
    }


    Player::velocity.x *= Player::airResistance;
    if (std::abs(Player::velocity.x) < Player::minVelocity) {
        Player::velocity.x = 0.f;
    }
    if (std::abs(Player::velocity.y) < Player::minVelocity) {
        Player::velocity.y = 0.f;
    }
    if (std::abs(Player::velocity.x) <= 1.f) {
        Player::velocity.x = 0.f;
    }
    Player::sprite.move(Player::velocity);

}

void Player::movePlayer(const float mdir_x, const float mdir_y) {
    Player::velocity.x += mdir_x * speedingUp;
    if (std::abs(Player::velocity.x) > maxVelocity) {
        Player::velocity.x = maxVelocity * ((Player::velocity.x < 0.f) ? -1.f : 1.f);
    }

}

void Player::animationTimerReset() {
    Player::animationTimer.restart();
    Player::SwitchAnimation = true;
}

bool Player::getSwitchAmination() {
    bool animSwitch = Player::SwitchAnimation;
    if (SwitchAnimation) {
        Player::SwitchAnimation = false;
    }
    return animSwitch;
}

sf::FloatRect Player::getGlobalBoundsPlayer() {
    return Player::sprite.getGlobalBounds();
}

void Player::resetGravityVelocity() {
    Player::velocity.y = 0.f;
}

void Player::setPlayerPosition(const float ppos_x, const float ppos_y) {
    Player::sprite.setPosition(ppos_x, ppos_y);
}

sf::Vector2f Player::getPlayerPosition() const {
    return Player::sprite.getPosition();
}







