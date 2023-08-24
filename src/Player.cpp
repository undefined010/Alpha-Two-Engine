#include "Player.h"
#include <cstdio>

Player::Player()
{
}

Player::Player(sf::Vector2f pos_ , const std::string& textureFilePath)
{
    this->texture = std::make_unique<sf::Texture>();
    this->player_pos = (pos_.x >= 0.f || pos_.y >= 0.f) ? pos_ : sf::Vector2f(X_PLAYER , Y_PLAYER); 

    this->isMoveable = false;
    this->player_velocity = 150.f;

    if (!this->texture->loadFromFile(textureFilePath)) fprintf(stderr,"faild to load player texture\n");

    this->sprite.setPosition(this->player_pos);
    this->sprite.setTexture(*this->texture);
}

Player::~Player()
{
}

void Player::setMovement(bool arg)
{
    this->isMoveable = arg;
}

bool Player::getMovement()
{
    return this->isMoveable;
}

const sf::Vector2f Player::getPlayerBounds()
{
    return sf::Vector2f(this->sprite.getGlobalBounds().width , this->sprite.getGlobalBounds().height);
}

const sf::Vector2f& Player::getPlayerPos()
{
    return this->player_pos;
}

void Player::setPlayerPos(const sf::Vector2f& pos)
{
    this->player_pos = pos;
}

void Player::setPlayerVelo(const float &velo) 
{
    this->player_velocity = velo;
}

void Player::collide(sf::RenderWindow &window) 
{
    if (this->player_pos.x <= 0.f){
        this->player_pos.x = 0.f;

    }
    
    if (this->player_pos.y <= 0.f){
        this->player_pos.y = 0.f;

    }

    if (this->player_pos.x + this->sprite.getGlobalBounds().width >= window.getSize().x){
        this->player_pos.x = window.getSize().x - this->sprite.getGlobalBounds().width;

    }

    if (this->player_pos.y + this->sprite.getGlobalBounds().height >= window.getSize().y) {
        this->player_pos.y = window.getSize().y - this->sprite.getGlobalBounds().height;
    
    }
    this->sprite.setPosition(this->player_pos);
}

void Player::move_keyboard(float deltaTime)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->player_pos.x +=  this->player_velocity * deltaTime;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->player_pos.x -= this->player_velocity * deltaTime;
    }

}

void Player::update(float deltaTime)
{
    if (this->isMoveable)
    {
        this->move_keyboard(deltaTime);
    }

    this->sprite.setPosition(this->player_pos);
}

void Player::render(sf::RenderWindow& window)
{
    this->collide(window);
    window.draw(this->sprite);
}