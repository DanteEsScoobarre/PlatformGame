#ifndef PLATFORMGAME_PLAYER_H
#define PLATFORMGAME_PLAYER_H
#include <SFML/Graphics.hpp>

enum class PlayerAnimState{
    Idle,
    MovingLeft,
    MovingRight,
    Jumping,
    Falling,
};


class Player {
public:
    Player();
    void updatePlayer();
    void renderPlayer(sf::RenderTarget & playerTarget);
    void movement();
    void initAnimations();
    void updateAnimatons();
    void updatePhysics();
    void movePlayer(float mdir_x, float mdir_y);
    void animationTimerReset();
    bool getSwitchAmination();
    sf::Vector2f getPlayerPosition() const;
    sf::FloatRect getGlobalBoundsPlayer();
    void resetGravityVelocity();
    void setPlayerPosition(float ppos_x, float ppos_y);




private:
    //Tekstury
    sf::Sprite sprite;
    sf::Texture textures;
    sf::IntRect currentFrame;

    //Animacje
    sf::Clock animationTimer;
    PlayerAnimState currentAnimState;
    bool SwitchAnimation;
    //Fizyka
    sf::Vector2f velocity;
    float maxVelocity;
    float minVelocity;
    float maxGravityVelocity;
    float speedingUp;
    float airResistance;
    float gravity;
    bool canJump;


    void initSprite();
    void initTextures();
    void initPhysics();


};


#endif //PLATFORMGAME_PLAYER_H
