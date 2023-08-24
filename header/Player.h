#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameObjs.h"

#include <memory>

#define X_PLAYER 0.f
#define Y_PLAYER 0.f

class Player : public game::Object
{
    private:
        std::unique_ptr<sf::Texture> texture;
        sf::Sprite sprite;
        sf::Vector2f player_pos;

    private:
        float player_velocity;



    public:
        bool isMoveable;
        void setPlayerVelo(const float &velo);
        void setMovement(bool arg);
        bool getMovement();

    public:
        void move_keyboard(float deltaTime);
        void collide(sf::RenderWindow &window);

    public:
        const sf::Vector2f& getPlayerPos();
        void setPlayerPos(const sf::Vector2f& pos_);
        const sf::Vector2f getPlayerBounds();

    public:
        void update(float deltaTime);
        void render(sf::RenderWindow& window);

    public:
        Player();
        Player(sf::Vector2f pos , const std::string& textureFilePath);
        ~Player();
};




#endif