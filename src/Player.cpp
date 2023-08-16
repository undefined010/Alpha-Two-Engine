#include "Player.h"
#include <cstdio>

Player::Player()
{
}

Player::Player(sf::Vector2f pos_ , const std::string& textureFilePath)
{
    this->texture = new sf::Texture();
    this->player_pos = (pos_.x >= 0.f || pos_.y >= 0.f) ? pos_ : sf::Vector2f(X_PLAYER , Y_PLAYER); // makes sure there are no negative values

    this->isMoveable = false;
    this->player_speed = 0.05f;

    if (!this->texture->loadFromFile(textureFilePath)) printf("shit\n");

    this->sprite.setPosition(this->player_pos);
    this->sprite.setTexture(*this->texture);
}

Player::~Player()
{
    // printf("destroied player\n");
    this->player_events.clear();
}

void Player::addPlayerEvents(const std::function<void()>& f)
{
    this->player_events.push_back(f);
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

void Player::move_keyboard()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->player_pos.x += 60.f * this->player_speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->player_pos.x -= 60.f * this->player_speed;
    }

}

void Player::update()
{
    if (this->isMoveable)
    {
        this->move_keyboard();
    }

    for (const auto& pl_events : this->player_events)
    {
        pl_events();
    }

    this->sprite.setPosition(this->player_pos);
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(this->sprite);
}