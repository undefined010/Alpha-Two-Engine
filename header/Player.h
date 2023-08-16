#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameObjs.h"

#include <SFML/Graphics.hpp>
#include <memory>

#define X_PLAYER 0.f
#define Y_PLAYER 0.f

class Player : public game::Object
{
    private:
        sf::Texture* texture;
        sf::Sprite sprite;
        sf::Vector2f player_pos;

    private:
        float player_speed;

    public:
        bool isMoveable;
        void setMovement(bool arg);
        bool getMovement();

    public:
        void move_keyboard();

    public:
        const sf::Vector2f& getPlayerPos();
        void setPlayerPos(const sf::Vector2f& pos_);
        const sf::Vector2f getPlayerBounds();

    public:
        void update();
        void render(sf::RenderWindow& window);

    public:
        Player();
        Player(sf::Vector2f pos , const std::string& textureFilePath);
        ~Player();
};




#endif